#ifndef ARRAYGOLDBACH_H
#define ARRAYGOLDBACH_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

typedef struct array_uint64{
    uint64_t contar;
    uint64_t capacidad;
    uint64_t* elemento;
} array_uint64_t;

void arrayGoldbach_uint64_init(array_uint64_t* array);

void arrayGoldbach_uint64_destroy(array_uint64_t* array);

void arrayGoldbach_uint64_add(array_uint64_t* array, uint64_t elemento);

void arrayGoldbach_uint64_get_elements(array_uint64_t* array);

void arrayGoldbach_uint64_get_count(array_uint64_t* array);

#endif ARRAYGOLDBACH_H