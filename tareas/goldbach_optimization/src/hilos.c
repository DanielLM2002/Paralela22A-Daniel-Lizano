#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include "asignados.h"
#include "arreglo_de_sumas.h"
#include "hilos.h"

int64_t MINIMO_PERMITIDO = 6;
primos_t primos;

arreglo_dinamico_t* calcular(arreglo_dinamico_t* number_data, uint64_t thread_count) {
    assert(number_data);

    // Se crea la memoria compartida para cada thread.
    datos_compartidos_t* shared_data = (datos_compartidos_t*)
        calloc(1, sizeof(datos_compartidos_t));
    // Cantidad de threads a crear.
    shared_data->cantidad_threads = thread_count;
    shared_data->primos = &primos;
    pthread_mutex_init(&shared_data->puedos_acceder_posicion, NULL);
    // Calcular la suma para cada num.
    for (int64_t index = 0; index < (int64_t)number_data->capacidad; index++) {
        nodoNumero_t* nodo_actual = &number_data->nodos[index];
        arreglo_primos_init(shared_data->primos);
        int64_t contenido_nodo_arreglo = labs(nodo_actual->num);
        generarPrimos(shared_data->primos, contenido_nodo_arreglo);
        shared_data->pre_sumas = (sumas_logradas*) calloc(primos.capacidad
                , sizeof(sumas_logradas));
        shared_data->posicion = 0;
        // Hace las operaciones para obtener todas las sumas.
        agreagarSumas(nodo_actual, shared_data);
        free(shared_data->pre_sumas);
        destroy_primos(shared_data->primos);
    }
    pthread_mutex_destroy(&shared_data->puedos_acceder_posicion);
    free(shared_data);
    return number_data;
}

void agreagarSumas(nodoNumero_t* num
        , datos_compartidos_t* shared_data) {
    // Inicializa memoria para los threads
    pthread_t* threads = (pthread_t*)
        calloc(shared_data->cantidad_threads, sizeof(pthread_t));
    // Inicializa memora para los number_data privados de los threads
    datos_privados_t* private_data = (datos_privados_t*)
        calloc(shared_data->cantidad_threads, sizeof(datos_privados_t));
    if (labs(num->num) < MINIMO_PERMITIDO) {
        num->bander = MENOR_A_5;
    } else if (esPar(num->num)) {
        crear_threads(num, threads, shared_data, private_data
        , sumaPar);
    } else {
        crear_threads(num, threads, shared_data, private_data
        , sumaImpar);
    }
    free(private_data);
    free(threads);
}

void* sumaPar(void* number_data) {
    assert(number_data);
    datos_privados_t* privados = (datos_privados_t*) number_data;
    datos_compartidos_t* compartidos = (datos_compartidos_t*)
        privados->shared_data;
    int64_t num = privados->num;
    primos_t* primos = compartidos->primos;
    // Datos necesarios para los calculos.
    int64_t numero_actual = labs(num);
    int64_t primer_digito;
    int64_t suma = 0;
    while (true) {
        // Se bloquea la posicion para evitar condiciones de carrera.
        pthread_mutex_lock(&compartidos->puedos_acceder_posicion);
        // Terminar el ciclo si ya se reccorieron todos los primos.
        if (compartidos->posicion < compartidos->primos->capacidad) {
            // Inicia desde la posicion que este libre.
            primer_digito = compartidos->posicion;
            // Aumenta la posicion para los siguientes threads.
            compartidos->posicion++;
        } else {
            // Librea la posicion para otros threads
            pthread_mutex_unlock(&compartidos->puedos_acceder_posicion);
            break;
        }
        pthread_mutex_unlock(&compartidos->puedos_acceder_posicion);
        int64_t segundo_digito = primer_digito;
        // Para el cola digito.
        while (segundo_digito < compartidos->primos->capacidad) {
            suma = primos->primos[primer_digito]
                + primos->primos[segundo_digito];
            // Si la suma es igual al num actual agregarla como suma.
            if (suma == numero_actual) {
                // Agrega la suma en la posicion que se está calculando
                sumas_Add(&compartidos->pre_sumas[primer_digito]
                    , primos->primos[primer_digito]
                    , primos->primos[segundo_digito]
                    , 0);
            }
            segundo_digito++;
        }
        suma = 0;
    }
    return NULL;
}

void* sumaImpar(void* number_data) {
    assert(number_data);
    datos_privados_t* privados = (datos_privados_t*) number_data;
    datos_compartidos_t* compartidos = (datos_compartidos_t*)
        privados->shared_data;
    int64_t num = privados->num;
    primos_t* primos = compartidos->primos;
    // Datos necesarios para los calculos.
    int64_t numero_actual = labs(num);
    int64_t primer_digito;
    int64_t suma = 0;
    while (true) {
        // Se bloquea la posicion para evitar condiciones de carrera.
        pthread_mutex_lock(&compartidos->puedos_acceder_posicion);
        // Terminar el ciclo si ya se reccorieron todos los primos.
        if (compartidos->posicion < compartidos->primos->capacidad) {
            // Inicia desde la posicion que este libre.
            primer_digito = compartidos->posicion;
            // Aumenta la posicion para los siguientes threads.
            compartidos->posicion++;
        } else {
            // Libera la posicion para otros threads
            pthread_mutex_unlock(&compartidos->puedos_acceder_posicion);
            break;
        }
        pthread_mutex_unlock(&compartidos->puedos_acceder_posicion);
        int64_t segundo_digito = primer_digito;
        while (segundo_digito < compartidos->primos->capacidad) {
            int64_t tercer_digito = segundo_digito;
            while (tercer_digito < (int64_t)primos->capacidad) {
                suma = primos->primos[primer_digito]
                    + primos->primos[segundo_digito]
                    + primos->primos[tercer_digito];
                if (suma == numero_actual) {
                    sumas_Add(&compartidos->pre_sumas[primer_digito]
                    , primos->primos[primer_digito]
                    , primos->primos[segundo_digito]
                    , primos->primos[tercer_digito]);
                }
                tercer_digito++;
            }
            segundo_digito++;
        }
        suma = 0;
    }
    return NULL;
}

bool esPar(int64_t num) {
    return (labs(num) % 2 == 0)? true : false;
}

void generarPrimos(primos_t* primos, int64_t contenido_nodo_arreglo) {
    assert(primos);
    for (int64_t supuesto_primo = 2; supuesto_primo <= contenido_nodo_arreglo
            ; supuesto_primo++) {
        int64_t es_primo = true;
        for (int64_t valor_actual = 2; valor_actual <= supuesto_primo
                ; valor_actual++) {
            int64_t operacion = supuesto_primo % valor_actual;
            if (operacion == 0 && supuesto_primo != valor_actual) {
                es_primo = 0;
                valor_actual = supuesto_primo + 1;
            }
        }
        if (es_primo) {
            primos_agregar(primos, supuesto_primo);
        }
    }
}


void crear_threads(nodoNumero_t* num, pthread_t* threads
        , datos_compartidos_t* shared_data
        , datos_privados_t* private_data
        , void* trabajo) {
    for (int64_t thread_actual = 0
            ; thread_actual < shared_data->cantidad_threads
            ; thread_actual++) {
        private_data[thread_actual].num = num->num;
        private_data[thread_actual].shared_data = shared_data;
        // Comienzan a trabajar en la posición 0.
        // Pone el thread actual a trabajar
        pthread_create(&threads[thread_actual], NULL, trabajo,
                &private_data[thread_actual]);
    }

    // Se espera a que cada thread termine su trabajo.
    for (int64_t thread_actual = 0
            ; thread_actual < shared_data->cantidad_threads
            ; thread_actual++) {
        pthread_join(threads[thread_actual], NULL);
    }
    // Junta las sumas de cada thread en el nodo.
    // Recorre el conjunto de capacidad de primos.
    for (int64_t index = 0; index < primos.capacidad; index++) {
        // Recorre cada nodo si existe
        sumas_logradas sumas_actuales = shared_data->pre_sumas[index];
        if (sumas_actuales.nodosSuma) {
            for (int64_t nodo = 0; nodo < (int64_t)sumas_actuales.capacidad
                    ; nodo++) {
                nodoSuma_t nodo_actual = sumas_actuales.nodosSuma[nodo];
                sumas_Add(num->sumas, nodo_actual.cabeza
                        , nodo_actual.cola, nodo_actual.auxiliar);
            }
        }
    }
    for (int64_t index = 0; index < primos.capacidad; index++) {
        if (shared_data->pre_sumas[index].nodosSuma) {
            sumas_delete(&shared_data->pre_sumas[index], true);
        }
    }
}
