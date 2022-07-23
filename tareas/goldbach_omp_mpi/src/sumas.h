/**
 * Copyright [2022] Daniel Lizano UCR
 */
#ifndef SUMAS_H
#define SUMAS_H

#include "asignados.h"
#include "arreglo_de_datos.h"

/* -------------------------------*/
/**
 * @brief Calcula la cantida de sums de numeros primes que
 * pueden dar como resultado un number.
 *
 * @param data Recibe un arreglo de objetos con un conjunto de data
 * para los cuales calculate sus sums.
 * @param thread_count Numero de threas que crear para realizar
 * las operaciones.
 *
 * @return Retorna un arreglo con todas las sums que generan cada valor.
 */
/* ---------------------------------*/
numbers_t* calculate(numbers_t* data, uint64_t thread_count);

void add_sums(numberNode_t* number, sums_t* un_sums, primos_t* primes
        , int64_t max_prime, int64_t amount_thread);

bool is_even(int64_t number);

void odd_sum(int64_t number, sums_t* un_sums, primos_t* primes
        , int64_t max_prime, int64_t amount_thread);

void even_sum(int64_t number, sums_t* un_sums, primos_t* primes
        , int64_t max_prime, int64_t amount_thread);

void multiple_sums(numberNode_t* number, sums_t* un_sums);

#endif  // SUMAS_H
