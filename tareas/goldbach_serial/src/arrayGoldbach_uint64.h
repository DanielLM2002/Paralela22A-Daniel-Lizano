#ifndef ARRAYGOLDBACH_H
#define ARRAYGOLDBACH_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

typedef struct arrayGoldbach_uint64{
    uint64_t contar;
    uint64_t capacidad;
    uint64_t* elemento;
} arrayGoldbach_uint64_t;

void arrayGoldbach_uint64_init(arrayGoldbach_uint64_t* array);

void arrayGoldbach_uint64_destroy(arrayGoldbach_uint64_t* array);

void arrayGoldbach_uint64_add(arrayGoldbach_uint64_t* array, uint64_t elemento);

void arrayGoldbach_uint64_get_elements(arrayGoldbach_uint64_t* array);

void arrayGoldbach_uint64_get_count(arrayGoldbach_uint64_t* array);

#endif ARRAYGOLDBACH_H