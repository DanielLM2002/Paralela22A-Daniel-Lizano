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

typedef struct nodo_arreglo nodo_arrego_t;

typedef struct arreglo {
  nodo_arrego_t * primero; 
  nodo_arrego_t * ultimo;
}arreglo_t;

void arreglo_init(arreglo_t * arreglo);

int64_t arreglo_nodo_conseguir_valor (nodo_arrego_t* arreglo);

int64_t arreglo_nodo_conseguir_posicion (nodo_arrego_t* arreglo);

nodo_arrego_t* arreglo_nodo_conseguir_siguiente(nodo_arrego_t * nodo);

arreglo_t* arreglo_nodo_conseguir_cola_goldbach(nodo_arrego_t * nodo);

nodo_arrego_t* arreglo_buscar (arreglo_t* arreglo, int64_t valor);

int arreglo_insertar (arreglo_t* arreglo, int64_t valor, int validez);

int arreglo_posible_insertar (arreglo_t* arreglo, int64_t valor, int validez);

void arreglo_destruir (arreglo_t* arreglo);

void arreglo_nodo_destruir (nodo_arrego_t* nodo_arreglo);

int arreglo_nodo_conseguir_validez(nodo_arrego_t * nodo);

#endif