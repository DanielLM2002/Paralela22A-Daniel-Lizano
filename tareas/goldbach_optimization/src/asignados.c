/**
 * Copyright [2022] Daniel Lizano UCR
 * Calse encargada de recibir el arreglo con las sumas y 
 * distribuir el trabajo
 */
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "asignados.h"

int64_t arreglo_primos_aumentar(primos_t* numero_primo);

void arreglo_primos_init(primos_t* numero_primo) {
    assert(numero_primo);
    numero_primo->tamanio = 0;
    numero_primo->capacidad = 0;
    numero_primo->primos = NULL;
}

void destroy_primos(primos_t* numero_primo) {
    assert(numero_primo);
    numero_primo->tamanio = 0;
    numero_primo->capacidad = 0;
    free(numero_primo->primos);
}


int64_t primos_agregar(primos_t* numero_primo, int64_t _valor) {
    assert(numero_primo);
    int error = EXIT_SUCCESS;
    if (numero_primo->capacidad == numero_primo->tamanio) {
        error = arreglo_primos_aumentar(numero_primo);
    }
    numero_primo->primos[numero_primo->capacidad] = _valor;
    numero_primo->capacidad++;
    return error;
}

int64_t distribuir_mapeo_dinamico(int64_t hilo, int64_t cantidad_datos
        , int64_t cantidad_threads) {
    int64_t min = (hilo > (cantidad_datos % cantidad_threads))
        ? cantidad_datos % cantidad_threads : hilo;
    int64_t division = floorl(cantidad_datos/cantidad_threads);
    return (hilo * division) + min;
}


int64_t arreglo_primos_aumentar(primos_t* numero_primo) {
    size_t nueva_capacidad = 2 * (numero_primo->tamanio? numero_primo->tamanio : 1);
    int64_t* nuevos_primos = (int64_t*)realloc(numero_primo->primos
            , nueva_capacidad * sizeof(int64_t));
    if (nuevos_primos) {
        numero_primo->tamanio = nueva_capacidad;
        numero_primo->primos = nuevos_primos;
        return EXIT_SUCCESS;
    } else {
        return 41;
    }
}
