/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de definir los metodos para la clase entrada
 * 
 */
#ifndef ENTREDA_H
#define ENTRADA_H
#include <stdint.h>
#include <inttypes.h>
#include <stdio.h>
#include <errno.h>

#include "arreglo_de_datos.h"


//#include "calculator.h"

typedef struct entrada {
  int error;
} entrada_t;


void entrada_init(entrada_t * interfaz);

int entrada_ejecutar();

void entrada_get_file(entrada_t * interfaz, arreglo_t * cola);

void ignorar_linea();

void entrada_validate(int * is_invalid);

void entrada_imprimir(arreglo_t * cola);

void entrada_imprimir_goldbach(arreglo_nodo_t* actual, int64_t valor);

void entrada_conseguir_sumas(arreglo_nodo_t* actual, int64_t valor);

#endif 