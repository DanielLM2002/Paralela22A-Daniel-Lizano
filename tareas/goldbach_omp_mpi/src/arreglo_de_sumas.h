/**
 * Copyright [2022] Daniel Lizano UCR
 */

#ifndef ARREGLO_SUMAS_H
#define ARREGLO_SUMAS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* -------------------------------*/
/**
 * @brief Guarda un suma que conciste en la suma de dos o tres numeros.
 */
/* ---------------------------------*/
typedef struct {
    int64_t state1;
    int64_t state2;
    int64_t state3;
} sumNode_t;

/* -------------------------------*/
/**
 * @brief Arreglo dinamico que guarda un conjunto de de nodosNumero.
 */
/* ---------------------------------*/
typedef struct {
    size_t capacity;
    size_t size;
    sumNode_t* sumNode;
} sums_t;
/* -------------------------------*/
/**
 * @brief Crea el arreglo dinámico para nodes suma.
 *
 * @param arreglo dirección al registro donde opera.
 */
/* ---------------------------------*/
sums_t* sums_create(void);
/* -------------------------------*/
/**
 * @brief Destruye el arreglo dinámico que se solicite.
 *
 * @param sum_num Dirección al arreeglo que se desea eleiminar.
 * @param is_valid_num TRUE: es un arreglo de sums_t por lo que no se debe
 * eliminar la dirección del arreglo que semando
 */
/* ---------------------------------*/
void sums_destroy(sums_t* sum_num, bool is_valid_num);
/* -------------------------------*/
/**
 * @brief Agrega un nodo suma a un arreglo dinamico.
 *
 * @param sum_num Dirección al arreglo donde se busca operar.
 * @param _primero Valor del primer dato del objeto.
 * @param _segundo Valor del state2 dato del objeto.
 * @param _tercero Valor del state3 dato del objeto.
 *
 * @return Retorna un código deerror si algo salió mal.
 */
/* ---------------------------------*/
int64_t sums_append(sums_t* sum_num, int64_t state1
        , int64_t state2, int64_t state3);

#endif  // ARREGLO_H
