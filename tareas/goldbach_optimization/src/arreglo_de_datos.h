#ifndef ARREGLO_NUMEROS_H
#define ARREGLO_NUMEROS_H

#include <stddef.h>
#include <stdint.h>

#include "arreglo_de_sumas.h"

enum {
    COMPLETO,
    FUERA_DE_RANGO,
    SIN_SUMAS,
    MENOR_A_5
};

typedef struct {
    int64_t num;
    sumas_logradas* sumas;
    int bander;
} nodoNumero_t;

typedef struct {
    size_t tamanio;
    size_t capacidad;
    nodoNumero_t* nodos;
} arreglo_dinamico_t;

void arreglo_dinamico_init(arreglo_dinamico_t* elemento);

void arreglo_dinamico_destroy(arreglo_dinamico_t* elemento);

int64_t arreglo_dinamico_append(arreglo_dinamico_t* elemento, int64_t valor, int validacion);

#endif // ARREGLO_NUMEROS_H