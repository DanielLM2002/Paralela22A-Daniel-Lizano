#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "arreglo_de_sumas.h"

sumas_logradas* arreglo_sumas_init(void) {
    sumas_logradas* sumas = (sumas_logradas*) calloc(1, sizeof(sumas_logradas));
    if (sumas) {
        sumas->tamanio = 0;
        sumas->capacidad = 0;
        sumas->nodosSuma = NULL;
    }
    return sumas;
}

void sumas_delete(sumas_logradas* sums, bool valid_num) {
    assert(sums);
    sums->tamanio = 0;
    sums->capacidad = 0;
    free(sums->nodosSuma);
    if (!valid_num) {
        free(sums);
    }
}


int64_t sumas_Add(sumas_logradas* sums, int64_t digito
    , int64_t digito2, int64_t digito3) {
    assert(sums);
    int64_t error = EXIT_SUCCESS;
    if (sums->capacidad == sums->tamanio) {
        error = sumas_push(sums);
    }
    sums->nodosSuma[sums->capacidad].cabeza = digito;
    sums->nodosSuma[sums->capacidad].cola = digito2;
    sums->nodosSuma[sums->capacidad].auxiliar = digito3;
    sums->capacidad++;
    return error;
}

int64_t sumas_push(sumas_logradas* sums) {
    size_t nueva_capacidad = 2 * (sums->tamanio ? sums->tamanio : 1);
    nodoSuma_t* nuevos_nodos = (nodoSuma_t*)realloc(sums->nodosSuma
            , nueva_capacidad * sizeof(nodoSuma_t));
    if (nuevos_nodos) {
        sums->tamanio = nueva_capacidad;
        sums->nodosSuma = nuevos_nodos;
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}