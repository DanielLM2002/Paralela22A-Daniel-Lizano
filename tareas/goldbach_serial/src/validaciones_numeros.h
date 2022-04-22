#ifndef VALIDACIONES_NUMEROS_H
#define VALIDACIONES_NUMEROS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>
#include <ctype.h>
#include "array_uint64.h"

bool validaciones(char* dato);

bool validar_negativo(uint64_t numero);

bool validar_par(uint64_t numero);

bool validar_primo(uint64_t numero);

bool es_fuerte(array_uint64_t suma, uint64_t numero1, uint64_t numero2);

bool es_debil(array_uint64_t suma, uint64_t numero1, uint64_t numero2,
             uint64_t numero3);

#endif