/**
 * Copyright [2022] Daniel Lizano UCR
 * clase encragada de realizar las sumas con mapero dinamico 
 * y enciar los resultados
 */
#ifndef SUMAS_H
#define SUMAS_H

#include <stdio.h>
#include "arreglo_de_datos.h"

/**
    * @brief Imprime la cantidad de sumas y cuales son.
    * @param salida El archivo donde se imprimiran las sumas.
    * @param nodo El nodo del arreglo de datos que contiene las sumas.
    */
void imprimir(FILE* salida, arreglo_dinamico_t* numeros);


/**
 * @brief Imprime un conjunto de sumas.
 *
 * @param sumas Dirección a una arreglo dinamico con las sumas.
 */
void imprimirSumas(FILE* salida, nodoNumero_t* nodo);
#endif  // SUMAS_H
