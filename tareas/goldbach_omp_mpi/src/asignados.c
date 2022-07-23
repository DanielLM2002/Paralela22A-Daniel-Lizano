
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <omp.h>

#include "asignados.h"

/* -------------------------------*/
/**
 * @brief Inicializa el arreglo diamico con una capacity inicial de 2.
 */
/* ---------------------------------*/
void asign_init(primos_t* prime_num) {
    assert(prime_num);
    prime_num->capacity = 0;
    prime_num->size = 0;
    prime_num->max_ammount = 0;
    prime_num->primes = NULL;
}

/* -------------------------------*/
/**
 * @brief Destruye los nodes creados y borra los valores anteriores.
 */
/* ---------------------------------*/
void asign_destroy(primos_t* prime_num) {
    assert(prime_num);
    prime_num->capacity = 0;
    prime_num->size = 0;
    free(prime_num->primes);
}

/* -------------------------------*/
/**
 * @brief Arega un elemento al arreglo y si no tiene espacioa para agregarar
 * aumenta su capacida el doble de la capacida actual.
 *
 * @return Retorna los errores que se puedan dar al intentar
 * aumentar la capacida del arreglo.
 */
/* ---------------------------------*/
int64_t asing_start(primos_t* prime_num, int64_t _valor) {
    assert(prime_num);
    int error = EXIT_SUCCESS;
    if (prime_num->size == prime_num->capacity) {
        error = asing_new_task(prime_num);
    }
    prime_num->primes[prime_num->size] = _valor;
    prime_num->size++;
    return error;
}

/* -------------------------------*/
/**
 * @brief Intenta realocar más memoria para el arreglo.
 *
 * @return Códigos de error:
 * 41: No se pudo crear más memoria para el arreglo.
 */
/* ---------------------------------*/
int64_t asing_new_task(primos_t* prime_num) {
    size_t nueva_capacidad = 2 * (prime_num->capacity? prime_num->capacity : 1);
    int64_t* nuevos_primos = (int64_t*)realloc(prime_num->primes
            , nueva_capacidad * sizeof(int64_t));
    if (nuevos_primos) {
        prime_num->capacity = nueva_capacidad;
        prime_num->primes = nuevos_primos;
        return EXIT_SUCCESS;
    } else {
        // No se pudo aumentar el tamaño del arreglo
        return 41;
    }
}
void assing_add_task(primos_t* prime_num) {
    assert(prime_num);
    int64_t supuesto_primo;
    if (prime_num->size) {
        supuesto_primo = prime_num->primes[prime_num->size-1]+1;
    } else {
        supuesto_primo = 2;
    }
    while (supuesto_primo <= prime_num->max_ammount) {
        int64_t es_primo = true;
        for (int64_t valor_actual = 2; valor_actual <= supuesto_primo
                ; valor_actual++) {
            int64_t operacion = supuesto_primo % valor_actual;
            if (operacion == 0 && supuesto_primo != valor_actual) {
                es_primo = 0;  // FALSE
                valor_actual = supuesto_primo + 1;
            }
        }
        if (es_primo) {
            asing_start(prime_num, supuesto_primo);
        }
        supuesto_primo++;
    }
}
int64_t task_limit(primos_t* prime_num, int64_t _valor) {
    assert(prime_num);
    // Genera más primos de ser necesario.
    if (prime_num->max_ammount < _valor) {
        prime_num->max_ammount = _valor;
        assing_add_task(prime_num);
    }
    int64_t indice = 0;
    while (indice < prime_num->size && prime_num->primes[indice] < _valor) {
        indice++;
    }
    return indice;
}
int64_t create_task(int64_t thread, int64_t cantidad_datos
        , int64_t cantidad_threads) {
    int64_t min = (thread > (cantidad_datos % cantidad_threads))
        ? cantidad_datos % cantidad_threads : thread;
    int64_t division = floorl(cantidad_datos/cantidad_threads);
    return (thread * division) + min;
}
