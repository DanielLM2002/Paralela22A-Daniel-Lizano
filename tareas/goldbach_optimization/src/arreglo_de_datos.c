/**
 * Copyright [2022] Daniel Lizano UCR
 * Arreglo de datos que permite alamcenar todo lo
 * ecnontrado en el archivo de entrada.
 */
#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "arreglo_de_datos.h"
#include "arreglo_de_sumas.h"


int64_t arreglo_dinamico_add(arreglo_dinamico_t* elemento);



void arreglo_dinamico_init(arreglo_dinamico_t* elemento) {
    assert(elemento);
    elemento->tamanio = 0;
    elemento->capacidad = 0;
    elemento->nodos = NULL;
}


void arreglo_dinamico_destroy(arreglo_dinamico_t* elemento) {
    assert(elemento);
    for (int64_t index = 0; index < (int64_t)elemento->capacidad; index++) {
        sumas_delete(elemento->nodos[index].sumas, false);
    }
    elemento->tamanio = 0;
    elemento->capacidad = 0;
    free(elemento->nodos);
}

int64_t arreglo_dinamico_append(arreglo_dinamico_t* elemento, int64_t valor, int validacion) {
    assert(elemento);
    int64_t error = EXIT_SUCCESS;
    if (elemento->capacidad == elemento->tamanio) {
        error = arreglo_dinamico_add(elemento);
    }
    // NOTE: memoria ya inicializada
    elemento->nodos[elemento->capacidad].num = valor;
    elemento->nodos[elemento->capacidad].bander = validacion;
    elemento->nodos[elemento->capacidad].sumas = arreglo_sumas_init();
    elemento->capacidad++;
    return error;
}


int64_t arreglo_dinamico_add(arreglo_dinamico_t* elemento) {
    size_t nueva_capacidad = 2 * (elemento->tamanio? elemento->tamanio : 1);
    nodoNumero_t* nuevos_nodos = (nodoNumero_t*)realloc(elemento->nodos
            , nueva_capacidad * sizeof(nodoNumero_t));
    if (nuevos_nodos) {
        elemento->tamanio = nueva_capacidad;
        elemento->nodos = nuevos_nodos;
        return EXIT_SUCCESS;
    } else {
        // No se pudo aumentar el tamaño del arreglo
        return EXIT_FAILURE;
    }
}

