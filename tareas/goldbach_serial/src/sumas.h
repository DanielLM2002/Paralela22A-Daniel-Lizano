#ifndef SUMAS_H
#define SUMAS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>
#include "arreglo_de_datos.h"

typedef struct sumas sumas_t;

sumas_t* sumas_create(char* dato);

void sumas_run(sumas_t* sumas);

void sumas_print(sumas_t* sumas);

void sumas_destroy(sumas_t* sumas);

#endif