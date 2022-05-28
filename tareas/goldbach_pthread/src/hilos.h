#ifndef HILOS_H
#define HILOS_H
#include <inttypes.h>
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>

#include"arreglo_de_datos.h"
#include"sumas.h"

typedef struct shared_data {
  cola_t * cola;
  uint64_t hilos;
} shared_data_t;

typedef struct private_data {
  cola_nodo_t * primero;
  cola_nodo_t * ultimo;
} private_data_t;

#endif