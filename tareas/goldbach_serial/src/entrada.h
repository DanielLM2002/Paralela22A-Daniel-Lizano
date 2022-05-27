/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de definir los metodos para la clase entrada
 * 
 */
#ifndef ENTRADA_H
#define ENTRADA_H
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include "arreglo_de_datos.h"

typedef struct entrada {
    int error;
}entrada_t;

/**
 * @brief inicializa la estructura de entrada
 * 
 * @param entrada 
 */
void entrada_init(entrada_t* entrada);

/**
 * @brief metodo para poder obtener el archivo de la entrada estandar
 * 
 * @param entrada 
 * @param array 
 */
void entrada_get_file(entrada_t* entrada, array_t* array);

/**
 * @brief validacion de que el char existe y sirve para el programa
 * 
 * @param is_valid 
 */
void entrada_validate(int64_t* is_valid);
/**
 * @brief metodo de impresion para la salida estandar
 * 
 * @param array 
 */
void entrada_print(array_t* array);
/**
 * @brief encargado de obtener las sumas e imprimirlas
 * 
 * @param current 
 * @param value 
 */

void entrada_print_sumas(arreglo_nodo_cola_t* current, int64_t value);

/**
 * @brief hecho para obtener las sumas para mandarlas a imprimir
 * 
 * @param current 
 * @param value 
 */
void get_sumas_entrada(arreglo_nodo_cola_t* current, int64_t value);
/**
 * @brief metodo para correr el programa
 * 
 * @return int64_t 
 */
int64_t run();

#endif
