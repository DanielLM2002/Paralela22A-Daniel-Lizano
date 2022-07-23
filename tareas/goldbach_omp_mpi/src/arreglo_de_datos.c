/**
 * Copyright [2022] Daniel Lizano UCR
 */
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include <omp.h>
#include "arreglo_de_datos.h"
#include "arreglo_de_sumas.h"






/**
 * @brief Inicializa el arreglo diamico con una capacity inicial de 2.
 */

void arreglo_init(numbers_t* num) {
    assert(num);
    num->capacity = 0;
    num->size = 0;
    num->nodes = NULL;
}


/**
 * @brief Destruye los nodes creados y borra los valores anteriores.
 */

void arreglo_destroy(numbers_t* num) {
    assert(num);
    for (int64_t index = 0; index < (int64_t)num->size; index++) {
        sums_destroy(num->nodes[index].sums, false);
    }
    num->capacity = 0;
    num->size = 0;
    free(num->nodes);
}


/**
 * @brief Arega un elemento al arreglo y si no tiene espacioa para agregarar
 * aumenta su capacida el doble de la capacida actual.
 *
 * @return Retorna los errores que se puedan dar al intentar
 * aumentar la capacida del arreglo.
 */

int64_t arreglo_add_number(numbers_t* num, int64_t value, int state) {
    assert(num);
    int64_t error = EXIT_SUCCESS;
    if (num->size == num->capacity) {
        error = array_alloc_more(num);
    }
    // NOTE: memoria ya inicializada
    num->nodes[num->size].number = value;
    num->nodes[num->size].validation = state;
    num->nodes[num->size].sums = sums_create();
    num->size++;
    return error;
}


/**
 * @brief Intenta realocar más memoria para el arreglo.
 *
 * @return Códigos de error.
 */

int64_t array_alloc_more(numbers_t* num) {
    size_t nueva_capacidad = 2 * (num->capacity? num->capacity : 1);
    numberNode_t* nuevos_nodos = (numberNode_t*)realloc(num->nodes
            , nueva_capacidad * sizeof(numberNode_t));
    if (nuevos_nodos) {
        num->capacity = nueva_capacidad;
        num->nodes = nuevos_nodos;
        return EXIT_SUCCESS;
    } else {
        // No se pudo aumentar el tamaño del arreglo
        return EXIT_FAILURE;
    }
}
