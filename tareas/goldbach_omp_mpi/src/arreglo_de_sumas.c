/**
 * Copyright [2022] Daniel Lizano UCR
 */
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <omp.h>

#include "arreglo_de_sumas.h"

/* -------------------------------*/
/**
 * @brief Inicializa el arreglo diamico con una capacity inicial de 2.
 */
/* ---------------------------------*/
sums_t* sums_create(void) {
    sums_t* sums = (sums_t*) calloc(1, sizeof(sums_t));
    if (sums) {
        sums->capacity = 0;
        sums->size = 0;
        sums->sumNode = NULL;
    }
    return sums;
}

/* -------------------------------*/
/**
 * @brief Destruye los elementos creados y borra los valores anteriores.
 */
/* ---------------------------------*/
void sums_destroy(sums_t* sum_num, bool is_valid_num) {
    assert(sum_num);
    sum_num->capacity = 0;
    sum_num->size = 0;
    free(sum_num->sumNode);
    if (!is_valid_num) {
        free(sum_num);
    }
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
int64_t sums_append(sums_t* sum_num, int64_t state1
        , int64_t state2, int64_t state3) {
    assert(sum_num);
    int64_t error = EXIT_SUCCESS;
    if (sum_num->size == sum_num->capacity) {
        error = sums_more_space(sum_num);
    }
    // NOTE: memoria ya inicializada.
    sum_num->sumNode[sum_num->size].state1 = state1;
    sum_num->sumNode[sum_num->size].state2 = state2;
    sum_num->sumNode[sum_num->size].state3 = state3;
    sum_num->size++;
    return error;
}

/* -------------------------------*/
/**
 * @brief Intenta realocar más memoria para el arreglo.
 *
 * @return Códigos de error.
 */
/* ---------------------------------*/
int64_t sums_more_space(sums_t* sum_num) {
    size_t new_space = 2 * (sum_num->capacity ? sum_num->capacity : 1);
    // NOTE: creo Array nodoSuma 0x55555555b340
    sumNode_t* nuevos_nodos = (sumNode_t*)realloc(sum_num->sumNode
            , new_space * sizeof(sumNode_t));
    if (nuevos_nodos) {
        sum_num->capacity = new_space;
        sum_num->sumNode = nuevos_nodos;
        return EXIT_SUCCESS;
    } else {
        // No se pudo aumentar el tamaño del arreglo
        return EXIT_FAILURE;
    }
}
