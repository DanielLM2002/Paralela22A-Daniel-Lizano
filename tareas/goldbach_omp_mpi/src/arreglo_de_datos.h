/**
 * Copyright [2022] Daniel Lizano UCR
 */
#ifndef ARREGLO_DE_DATOS_H
#define ARREGLO_DE_DATOS_H

#include <stddef.h>
#include <stdint.h>
#include <omp.h>

#include "arreglo_de_sumas.h"

enum {
    COMPLETO,
    FUERA_DE_RANGO,
    SIN_SUMAS,
    MENOR_A_5
};


typedef struct {
    int64_t number;
    sums_t* sums;
    int validation;
} numberNode_t;


typedef struct {
    size_t capacity;
    size_t size;
    numberNode_t* nodes;
} numbers_t;
/* -------------------------------*/
/**
 * @brief Crea el arreglo dinámico para nodes number.
 *
 * @param num dirección al registro donde opera.
 */
/* ---------------------------------*/
void arreglo_init(numbers_t* num);
/* -------------------------------*/
/**
 * @brief Destruye el arreglo dinámico que se solicite.
 *
 * @param num Dirección al arreeglo que se desea eleiminar.
 */
/* ---------------------------------*/
void arreglo_destroy(numbers_t* num);

/* -------------------------------*/
/**
 * @brief Agrega un nodo number a un arreglo dinamico.
 *
 * @param num Dirección al num donde se busca opera
 * @param value Es el number que se va a guardar en el nodo.
 * @param state Identificador del nodo.
 *
 * @return Retorna un código deerror si algo salió mal.
 */
/* ---------------------------------*/
int64_t arreglo_add_number(numbers_t* num, int64_t value, int state);

/**
 * @brief allocar mas memoria para el arreglo.
 * 
 * @param num 
 * @return int64_t 
 */
int64_t array_alloc_more(numbers_t* num);

#endif  // ARREGLO_H
