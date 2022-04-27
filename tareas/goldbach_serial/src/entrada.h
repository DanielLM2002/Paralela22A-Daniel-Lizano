#ifndef ENTRADA_H
#define ENTRADA_H
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <inttypes.h>
#include "arreglo_de_datos.h"

typedef struct entrada{
    int error;
}entrada_t;

void entrada_init(entrada_t* entry);

void entrada_get_file(entrada_t* entry, arreglo_de_datos_t* array);

void entrada_validate(int64_t* is_valid);

void entrada_print(arreglo_de_datos_t* array);

void entrada_print_sumas(arreglo_nodo_t* current, int64_t value);

void get_sumas_entrada(arreglo_nodo_t* current, int64_t value);

int64_t run();

#endif