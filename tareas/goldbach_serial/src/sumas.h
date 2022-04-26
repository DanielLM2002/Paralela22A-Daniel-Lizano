#ifndef SUMAS_H
#define SUMAS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>
#include "arreglo_de_datos.h"

int suma_goldbach_total(arreglo_de_datos_t* array);

int suma_par(arreglo_de_datos_t* array_sums, int64_t number);

int suma_goldbach_numero(arreglo_de_datos_t* array_sums, int64_t number);

bool suma_prima(int64_t number);

int suma_impar(arreglo_de_datos_t* array_sums, int64_t number);

#endif