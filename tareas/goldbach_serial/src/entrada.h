#ifndef ENTRADA_H
#define ENTRADA_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>
#include <ctype.h>

typedef struct array_nodo{//queue node
    uint64_t elemento;
    array_nodo_t* siguiente;
    uint64_t contador;
    uint64_t numero_invalido;
}array_nodo_t;

typedef struct array_lectura array_lectura_t;

typedef struct array_lectura{//queue data
    array_nodo_t* cabeza;
    array_nodo_t* cola;
}array_lectura_t;

void array_lectura_init(array_nodo_t* array_nodo);

uint64_t array_lectura_append(array_lectura_t* array_lectura, uint64_t valor,
                                uint64_t numero_invalido);

uint64_t array_lectura_insert(array_lectura_t* array_lectura, uint64_t valor,
                                uint64_t numero_invalido);

array_nodo_t* array_lectura_buscar(array_lectura_t* actual, uint64_t valor);

void array_lectura_destroy(array_lectura_t* array_lectura);

void array_nodo_destroy(array_nodo_t* array_nodo);

uint64_t array_nodo_obtener_elemento(array_nodo_t* nodo);

uint64_t array_nodo_obtener_contador(array_nodo_t* nodo);








#endif