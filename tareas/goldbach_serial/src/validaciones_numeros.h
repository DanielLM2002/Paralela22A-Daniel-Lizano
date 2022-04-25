#ifndef VALIDACIONES_NUMEROS_H
#define VALIDACIONES_NUMEROS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>
#include <ctype.h>
#include <string.h>


bool validaciones(char* dato);

bool validar_negativo(uint64_t numero);//

bool validar_par(uint64_t numero);//

bool es_valido(uint64_t numero);

bool validar_primo(uint64_t numero);//

bool es_fuerte(uint64_t numero);

bool es_debil(uint64_t numero);

#endif