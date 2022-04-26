#ifndef ARREGLO_DE_DATOS_H
#define ARREGLO_DE_DATOS_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

typedef struct arreglo_nodo arreglo_nodo_t;

typedef struct arreglo_de_datos{
    arreglo_nodo_t* cabeza;
    arreglo_nodo_t* cola;
    uint64_t* elemento;
} arreglo_de_datos_t;

void arreglo_init(arreglo_de_datos_t* arreglo);

int64_t get_value_arreglo(arreglo_nodo_t* arreglo);

int64_t get_posicion_arreglo(arreglo_nodo_t* nodo);

arreglo_nodo_t* get_siguiente(arreglo_nodo_t* nodo);

int insert(arreglo_de_datos_t* arreglo, int64_t value, int valid);

arreglo_de_datos_t* get_arreglo_sumas_goldbach(arreglo_nodo_t* nodo);

arreglo_nodo_t* search(arreglo_de_datos_t* arreglo, int64_t value);

void nodo_destroy(arreglo_nodo_t* nodo);

void arreglo_destroy(arreglo_de_datos_t* arreglo);

int nodo_validate(arreglo_nodo_t* nodo);

int array_insertion (arreglo_de_datos_t* arreglo, int64_t value, int valid);
#endif