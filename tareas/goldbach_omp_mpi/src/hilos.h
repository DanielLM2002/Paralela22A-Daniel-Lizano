/**
 * Copyright [2022] Daniel Lizano UCR
 */
#ifndef HILOS_H
#define HILOS_H

#include <stdio.h>
#include "arreglo_de_datos.h"

/* -------------------------------*/
/**
 * @brief Imprime en la salida estandar sums de goldbac.
 *
 * @param salida Dirección a la salida estandar.
 * @param sums Arreglo con las sums a print.
 */
/* ---------------------------------*/
void print(FILE* salida, numbers_t* numeros);

#endif  // HILOS_H
