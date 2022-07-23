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

/* -------------------------------*/
/**
 * @brief Guarda un number con su respectibo valor un conjunto de sums
 * y una bandera para identificar su condición.
 * @details Banderas:
 * @details VALIDO: que el number se debe realizar todo el
 * procedimiento normal.
 * @details FUERA_DE_RANGO: que no se debe calcular y debe print 'NA'.
 * @details SIN_SUMAS: realiza el calculo pero solo imprime la cantidad
 * de sums, sin mostrar cuales son.
 */
/* ---------------------------------*/
typedef struct {
    int64_t number;
    sums_t* sums;
    int validation;
} numberNode_t;

/* -------------------------------*/
/**
 * @brief Arreglo dinamico que guarda un conjunto de de nodosNumero.
 */
/* ---------------------------------*/
typedef struct {
    size_t capacity;
    size_t size;
    numberNode_t* nodes;
} numbers_t;
/* -------------------------------*/
/**
 * @brief Crea el arreglo dinámico para nodes number.
 *
 * @param arreglo dirección al registro donde opera.
 */
/* ---------------------------------*/
void arreglo_init(numbers_t* num);
/* -------------------------------*/
/**
 * @brief Destruye el arreglo dinámico que se solicite.
 *
 * @param arreglo Dirección al arreeglo que se desea eleiminar.
 */
/* ---------------------------------*/
void arreglo_destroy(numbers_t* num);

/* -------------------------------*/
/**
 * @brief Agrega un nodo number a un arreglo dinamico.
 *
 * @param _numeros Dirección al arreglo donde se busca opera
 * @param _valor Es el number que se va a guardar en el nodo.
 * @param _bandera Identificador del nodo.
 *
 * @return Retorna un código deerror si algo salió mal.
 */
/* ---------------------------------*/
int64_t arreglo_add_number(numbers_t* num, int64_t value, int state);

#endif  // ARREGLO_H
