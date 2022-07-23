
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
int64_t asing_start(primos_t* prime_num, int64_t num_value) {
    assert(prime_num);
    int error = EXIT_SUCCESS;
    if (prime_num->size == prime_num->capacity) {
        error = asing_new_task(prime_num);
    }
    prime_num->primes[prime_num->size] = num_value;
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
    size_t new_task_assigned = 2 * (prime_num->capacity? prime_num->capacity : 1);
    int64_t* new_primes = (int64_t*)realloc(prime_num->primes
            , new_task_assigned * sizeof(int64_t));
    if (new_primes) {
        prime_num->capacity = new_task_assigned;
        prime_num->primes = new_primes;
        return EXIT_SUCCESS;
    } else {
        // No se pudo aumentar el tamaño del arreglo
        return 41;
    }
}
void assing_add_task(primos_t* prime_num) {
    assert(prime_num);
    int64_t possible_prime;
    if (prime_num->size) {
        possible_prime = prime_num->primes[prime_num->size-1]+1;
    } else {
        possible_prime = 2;
    }
    while (possible_prime <= prime_num->max_ammount) {
        int64_t is_prime = true;
        for (int64_t current_value = 2; current_value <= possible_prime
                ; current_value++) {
            int64_t task = possible_prime % current_value;
            if (task == 0 && possible_prime != current_value) {
                is_prime = 0;  // FALSE
                current_value = possible_prime + 1;
            }
        }
        if (is_prime) {
            asing_start(prime_num, possible_prime);
        }
        possible_prime++;
    }
}
int64_t task_limit(primos_t* prime_num, int64_t num_value) {
    assert(prime_num);
    // Genera más primos de ser necesario.
    if (prime_num->max_ammount < num_value) {
        prime_num->max_ammount = num_value;
        assing_add_task(prime_num);
    }
    int64_t index = 0;
    while (index < prime_num->size && prime_num->primes[index] < num_value) {
        index++;
    }
    return index;
}
int64_t create_task(int64_t thread, int64_t data_amount
        , int64_t thread_number) {
    int64_t min = (thread > (data_amount % thread_number))
        ? data_amount % thread_number : thread;
    int64_t division = floorl(data_amount/thread_number);
    return (thread * division) + min;
}
