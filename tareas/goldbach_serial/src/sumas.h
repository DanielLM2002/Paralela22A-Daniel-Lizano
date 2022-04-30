/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de definir los metodos
 * para la clase de sumas
 * 
 */
#ifndef SUMAS_H
#define SUMAS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>
#include "arreglo_de_datos.h"
/**
 * @brief metodo para generar el arreglo a usar
 * 
 * @param array 
 * @return int 
 */
int suma_goldbach_total(arreglo_de_datos_t* array);
/**
 * @brief metodo para revisar si la suma es par
 * 
 * @param array_sums 
 * @param number 
 * @return int 
 */
int suma_par(arreglo_de_datos_t* array_sums, int64_t number);
/**
 * @brief meter los numeros en el arreglo
 * 
 * @param array_sums 
 * @param number 
 * @return int 
 */
int suma_goldbach_numero(arreglo_de_datos_t* array_sums, int64_t number);
/**
 * @brief revisar si la suma es de numeros primos
 * 
 * @param number 
 * @return true 
 * @return false 
 */
bool suma_prima(int64_t number);
/**
 * @brief revisar si la suma es de numeros impar
 * 
 * @param array_sums 
 * @param number 
 * @return int 
 */
int suma_impar(arreglo_de_datos_t* array_sums, int64_t number);

#endif
