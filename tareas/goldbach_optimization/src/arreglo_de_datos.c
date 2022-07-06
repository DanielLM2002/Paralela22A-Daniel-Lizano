
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



