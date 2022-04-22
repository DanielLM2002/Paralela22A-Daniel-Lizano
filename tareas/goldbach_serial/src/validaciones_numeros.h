#ifndef VALIDACIONES_NUMEROS
#define VALIDACIONES_NUMEROS
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <assert.h>
#include <stdbool.h>
#include <inttypes.h>
#include <ctype.h>
#include "array_uint64.h"

typedef struct validaciones validaciones;

typedef struct validaciones{
    char* entrada;
    bool numero_valido;
    bool verificar;
    bool validar_negativo;
    bool validar_par;
    bool validar_primo;
    bool es_positivo;
    uint64_t valor;
    uint64_t contar;
    array_uint64_t* numeros_primos;
    array_uint64_t* suma;
}validaciones_t;

validaciones_t* validaciones_create(char* entrada);

bool validaciones(char* entrada);

bool validar_negativo(char* entrada);

bool validar_par(char* entrada);

bool validar_primo(char* entrada);

bool es_fuerte(array_uint64_t suma, uint64_t numero1, uint64_t numero2);

bool es_debil(array_uint64_t suma, uint64_t numero1, uint64_t numero2,
             uint64_t numero3);

#endif