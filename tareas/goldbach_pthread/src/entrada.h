/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de definir los metodos para la clase entrada
 * 
 */
#ifndef ENTRADA_H
#define ENTRADA_H
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <errno.h>

#include "arreglo_de_datos.h"

typedef struct entrada {
  int error;
} entrada_t;


int entrada_ejecutar(int argc, char* argv[]);

int64_t entrada_validacion_entrada(int argc, char* argv[]);

int entrada_get_file(arreglo_t* cola);

void ignorar_linea();

void entrada_validate(int* is_invalid);

void entrada_imprimir(arreglo_t* cola);

void entrada_imprimir_goldbach(arreglo_nodo_t* actual, int64_t valor,
                                int64_t sumas);

int entrada_conseguir_sumas(arreglo_nodo_t* actual, int64_t valor);

#endif
