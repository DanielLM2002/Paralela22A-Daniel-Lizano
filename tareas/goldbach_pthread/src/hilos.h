/**
 * Copyright [2022] Daniel Lizano UCR
Clase encargada de definir los metodos de los hilos
 * 
 */
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
  arreglo_t * cola;
  uint64_t hilos;
} shared_data_t;

typedef struct private_data {
  arreglo_nodo_t* primero;
  arreglo_nodo_t* ultimo;
} private_data_t;

shared_data_t* pthread_init_shdata(arreglo_t* cola, uint64_t hilos);

int pthread_crear_hilos(shared_data_t* shared_data);

void pthread_repartir(private_data_t* private_array,
    shared_data_t* shared_data);
#endif