#ifndef SUMAS_H
#define SUMAS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>
#include "arreglo_de_datos.h"

int sumas_total(arreglo_de_datos_t* arreglo);

int suma_de_numeros(arreglo_de_datos_t* array_sums, int64_t number);

int suma_de_pares(arreglo_de_datos_t* array_sums, int64_t number);


#endif