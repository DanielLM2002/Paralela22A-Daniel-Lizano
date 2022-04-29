#include "arreglo_de_datos.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef struct arreglo_nodo {

    
    arreglo_de_datos_t arreglo_sumas;

    arreglo_nodo_t* next;

    int64_t position;

    int64_t value;

    int validate;

} arreglo_nodo_t;

void arreglo_init(arreglo_de_datos_t* arreglo) {
    assert(arreglo);
    arreglo -> cabeza = NULL;
    arreglo -> cola = NULL;
}

int64_t get_value_arreglo(arreglo_nodo_t* arreglo) {
    return arreglo -> value;
}

int64_t get_posicion_arreglo(arreglo_nodo_t* nodo) {
    return nodo -> position;
}

arreglo_nodo_t* get_siguiente(arreglo_nodo_t* nodo) {
    return nodo -> next;
}

int insert(arreglo_de_datos_t* arreglo, int64_t value, int valid) {
    assert(arreglo);
    int error = EXIT_SUCCESS;
    arreglo_nodo_t* new_nodo = (arreglo_nodo_t*) calloc(1, 
                                sizeof(arreglo_nodo_t));
    if(new_nodo) {
        new_nodo -> value = value;
        new_nodo -> position = 1;
        new_nodo -> validate = valid;
        arreglo_init(&new_nodo -> arreglo_sumas);

        if(arreglo -> cola == NULL) {
            arreglo -> cabeza = new_nodo;
            arreglo -> cola = new_nodo;
        }
        else {
            arreglo -> cola -> next = new_nodo;
            arreglo -> cola = arreglo -> cola -> next;
        }
    } 
    else {
        error = EXIT_FAILURE;
        fprintf(stderr,"Nos quedamos sin espacio de memoria");
    }
    return error;
}

arreglo_de_datos_t* get_arreglo_sumas_goldbach(arreglo_nodo_t* nodo) {
    return &nodo->arreglo_sumas;
}


arreglo_nodo_t* search(arreglo_de_datos_t* arreglo, int64_t searching) {
    assert(arreglo);
    arreglo_nodo_t* actual = arreglo ->cabeza;
    while(actual->value) {
        if(actual->value != searching){
            actual = actual -> next;
        }
    }
    return actual;
}

void nodo_destroy(arreglo_nodo_t* nodo) {
    nodo->value =0;
    arreglo_destroy(&nodo ->arreglo_sumas);
    free(nodo);
}

void arreglo_destroy(arreglo_de_datos_t* arreglo) {
    assert(arreglo);
    arreglo_nodo_t* actual = arreglo->cabeza;
    arreglo_nodo_t* borrar = NULL;
    while(actual) {
        borrar = actual -> next;
        nodo_destroy(actual);
        actual = borrar;
    }
    arreglo->cabeza=NULL;
    arreglo->cola=NULL;
}
int nodo_validate(arreglo_nodo_t* nodo) {
    return nodo->validate;
}

int array_insertion (arreglo_de_datos_t* arreglo, int64_t value, int valid) {
    assert(arreglo);
    int error = EXIT_SUCCESS;
    error = insert(arreglo, value, valid);
    return error;
}