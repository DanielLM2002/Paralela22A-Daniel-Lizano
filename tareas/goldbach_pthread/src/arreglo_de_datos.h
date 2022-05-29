/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de definir los metodos de la clase
 * arreglo de datos
 * 
 */
#ifndef ARREGLO_DE_DATOS_H
#define ARREGLO_DE_DATOS_H
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct arreglo_nodo arreglo_nodo_t;

typedef struct arreglo {
  arreglo_nodo_t * primero;
  arreglo_nodo_t * ultimo;
  int64_t tamanio;
}arreglo_t;

void arreglo_init(arreglo_t * cola);

int64_t arreglo_nodo_conseguir_valor(arreglo_nodo_t* cola);

int64_t arreglo_nodo_conseguir_posicion(arreglo_nodo_t* cola);

arreglo_nodo_t* arreglo_nodo_conseguir_siguiente(arreglo_nodo_t* nodo);

arreglo_t * arreglo_nodo_conseguir_cola_goldbach(arreglo_nodo_t* nodo);

arreglo_nodo_t* arreglo_buscar(arreglo_t* cola, int64_t valor);

int arreglo_insertar(arreglo_t* cola, int64_t valor, int validez);

int arreglo_posible_insertar(arreglo_t* cola, int64_t valor, int validez);

void arreglo_destruir(arreglo_t* cola);

void arreglo_nodo_destruir(arreglo_nodo_t* cola_nodo);

int arreglo_nodo_conseguir_validez(arreglo_nodo_t* nodo);

#endif
