#include "array_uint64.h"


void aumentar_tamaño(array_uint64_t* array);

void array_uint64_init(array_uint64_t* array){
    assert(array);
    array -> contar = 0;
    array -> capacidad = 0;
    array -> elemento = NULL;
}

void array_uint64_destroy(array_uint64_t* array){
    assert(array);
    array -> contar = 0;
    array -> capacidad = 0;
    free(array -> elemento);
}

void array_uint64_add(array_uint64_t* array, uint64_t elemento){
    assert(array);
    if(array -> contar == array -> capacidad){
        aumentar_tamaño(array);
    }
    array -> elemento[array -> contar++] = elemento;
}

void aumentar_tamaño(array_uint64_t* array){
    assert(array);
    uint64_t nuevaCapacidad = 10 * (array -> capacidad ? array -> capacidad : 1);
    uint64_t* nuevosElementos = (uint64_t*) realloc(array-> elemento, nuevaCapacidad * sizeof(uint64_t));
    if (nuevosElementos){
        array -> capacidad = nuevaCapacidad;
        array -> elemento = nuevosElementos;
    }
}

uint64_t array_uint64_get_count(array_uint64_t* array){
    assert(array);
    return array ->contar;
}

uint64_t* array_uint64_get_elements(array_uint64_t* array){
    assert(array);
    return array ->elemento;
}