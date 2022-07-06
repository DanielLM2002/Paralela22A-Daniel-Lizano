#include <assert.h>
#include <stdint.h>
#include <stdlib.h>

#include "asignados.h"

int64_t arreglo_primos_aumentar(primos_t* numero_primo);

void arreglo_primos_init(primos_t* numero_primo) {
    assert(numero_primo);
    numero_primo->tamanio = 0;
    numero_primo->capacidad = 0;
    numero_primo->primos = NULL;
}

void destroy_primos(primos_t* numero_primo) {
    assert(numero_primo);
    numero_primo->tamanio = 0;
    numero_primo->capacidad = 0;
    free(numero_primo->primos);
}


int64_t primos_agregar(primos_t* numero_primo, int64_t _valor) {
    assert(numero_primo);
    int error = EXIT_SUCCESS;
    if (numero_primo->capacidad == numero_primo->tamanio) {
        error = arreglo_primos_aumentar(numero_primo);
    }
    numero_primo->primos[numero_primo->capacidad] = _valor;
    numero_primo->capacidad++;
    return error;
}