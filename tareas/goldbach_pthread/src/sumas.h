/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de definir los metodos
 * para la clase de sumas
 * 
 */\
#ifndef SUMAS_H
#define SUMAS_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>
#include "arreglo_de_datos.h"

int goldbach_suma_total(arreglo_t * cola);

int goldbach_suma_numero(int64_t numero, arreglo_t* cola_goldbach);

bool goldbach_es_primo(int64_t numero);

int goldbach_par(int64_t numero, arreglo_t* cola_goldbach);

int goldbach_impar(int64_t numero, arreglo_t* cola_goldbach);

void* goldbach_cola_secundaria(void* cola);
#endif
