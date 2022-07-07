/**
 * Copyright [2022] Daniel Lizano UCR
 * Arreglo de datos que permite alamcenar todo lo
 * ecnontrado en el archivo de entrada.
 */
#ifndef ARREGLO_NUMEROS_H
#define ARREGLO_NUMEROS_H

#include <stddef.h>
#include <stdint.h>

#include "arreglo_de_sumas.h"

enum {
    COMPLETO,
    FUERA_DE_RANGO,
    SIN_SUMAS,
    MENOR_A_5
};

typedef struct {
    int64_t num;
    sumas_logradas* sumas;
    int bander;
} nodoNumero_t;

typedef struct {
    size_t tamanio;
    size_t capacidad;
    nodoNumero_t* nodos;
} arreglo_dinamico_t;

/**
 * @brief Crea el arreglo dinámico para nodos numero.
 *
 * @param arreglo dirección al registro donde opera.
 */
void arreglo_dinamico_init(arreglo_dinamico_t* elemento);

/**
 * @brief Destruye el arreglo dinámico que se solicite.
 *
 * @param arreglo Dirección al arreeglo que se desea eleiminar.
 */
void arreglo_dinamico_destroy(arreglo_dinamico_t* elemento);

/**
 * @brief Agrega un nodo numero a un arreglo dinamico.
 *
 * @param elemento Dirección al arreglo donde se busca opera
 * @param valor Es el valor que entrara al arreglo.
 * @param validacion validador del estado del nodo
 *
 * @return Retorna un código deerror si algo salió mal.
 */
int64_t arreglo_dinamico_append(arreglo_dinamico_t* elemento, int64_t valor, int validacion);

#endif // ARREGLO_NUMEROS_H