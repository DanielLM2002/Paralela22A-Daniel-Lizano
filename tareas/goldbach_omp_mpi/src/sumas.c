/**
 * Copyright [2022] Daniel Lizano UCR
 */
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>


#include "asignados.h"
#include "arreglo_de_sumas.h"
#include "sumas.h"

int64_t allowed_tasks = 6;
primos_t primes;





numbers_t* calculate(numbers_t* data, uint64_t thread_count) {
    assert(data);

    asign_init(&primes);
    // Calcular la addition para cada number.
    for (int64_t index = 0; index < (int64_t)data->size; index++) {
        numberNode_t* current_node = &data->nodes[index];
        int64_t max_ammount = labs(current_node->number);
        // Obtiene el limite de primes para el nodo actual.
        int64_t max_prime = task_limit(&primes, max_ammount);
        // Crea el conjunto de un_sums donde guardar las sums que se
        // encuentren para este nodo number.
        sums_t* un_sums = (sums_t*) calloc(primes.size
                , sizeof(sums_t));
        // Hace las operaciones para obtener todas las sums.
        add_sums(current_node, un_sums, &primes, max_prime
                , thread_count);
        free(un_sums);
    }
    return data;
}

void add_sums(numberNode_t* number, sums_t* un_sums, primos_t* primes
        , int64_t max_prime, int64_t amount_thread) {
    // Se crean los hilos
    {
        if (labs(number->number) < allowed_tasks) {
            number->validation = MENOR_A_5;
        } else if (is_even(number->number)) {
            even_sum(number->number, un_sums, primes, max_prime
                    , amount_thread);
            multiple_sums(number, un_sums);
        } else {
            odd_sum(number->number, un_sums, primes, max_prime
                    , amount_thread);
            multiple_sums(number, un_sums);
        }
    }
}

void even_sum(int64_t number, sums_t* un_sums, primos_t* primes
        , int64_t max_prime, int64_t amount_thread) {
    assert(primes);
    assert(un_sums);
    int64_t current_number = labs(number);
    #pragma omp parallel for num_threads(cantidad_threads) default(none)\
        shared(current_number, un_sums, primes, max_prime\
            , amount_thread) schedule(dynamic)
    for (int first_part = 0; first_part < max_prime
            ; first_part++) {
        int64_t second_part = first_part;
        // Para el state2 digito.
        while (second_part < max_prime) {
            int64_t addition = primes->primes[first_part]
                + primes->primes[second_part];
            // Si la addition es igual al number actual agregarla como addition.
            if (addition == current_number) {
                // Agrega la addition en la posicion que se está calculando
                sums_append(&un_sums[first_part]
                    , primes->primes[first_part]
                    , primes->primes[second_part]
                    , 0);
            }
            second_part++;
        }
    }
}
void odd_sum(int64_t number, sums_t* un_sums, primos_t* primes
        , int64_t max_prime, int64_t amount_thread) {
    assert(primes);
    assert(un_sums);
    int64_t current_number = labs(number);
    #pragma omp parallel for num_threads(cantidad_threads) default(none)\
        shared(current_number, un_sums, primes, max_prime\
                , amount_thread) schedule(dynamic)
    for (int first_part = 0; first_part < max_prime
            ; first_part++) {
        int64_t second_part = first_part;
        // Para el state2 digito.
        while (second_part < max_prime) {
            // Para el tercer digito.
            int64_t third_part = second_part;
            while (third_part < max_prime) {
                int64_t addition = primes->primes[first_part]
                    + primes->primes[second_part]
                    + primes->primes[third_part];
                if (addition == current_number) {
                    sums_append(&un_sums[first_part]
                        , primes->primes[first_part]
                        , primes->primes[second_part]
                        , primes->primes[third_part]);
                }
                third_part++;
            }
            second_part++;
        }
    }
}

bool is_even(int64_t number) {
    return (labs(number) % 2 == 0)? true : false;
}

void multiple_sums(numberNode_t* number, sums_t* un_sums) {
    // Junta las sums de cada thread en el nodo.
    // Recorre el conjunto de un_sums que son del size de primes.
    for (int64_t index = 0; index < primes.size; index++) {
        // Recorre cada nodo addition si existe
        sums_t actual_sums = un_sums[index];
        if (actual_sums.sumNode) {
            for (int64_t nodo = 0; nodo < (int64_t)actual_sums.size
                    ; nodo++) {
                sumNode_t current_node = actual_sums.sumNode[nodo];
                sums_append(number->sums, current_node.state1
                        , current_node.state2, current_node.state3);
            }
        }
    }
    // Elimina las sums.
    for (int64_t index = 0; index < primes.size; index++) {
        if (un_sums[index].sumNode) {
            sums_destroy(&un_sums[index], true);
        }
    }
}
