#ifndef HILOS_H
#define HILOS_H

#include "asignados.h"
#include "arreglo_de_datos.h"

//  shared data para todos los hilos 
typedef struct shared_data {
    int64_t cantidad_threads;
    primos_t* primos;
    int64_t posicion;
    sumas_logradas* pre_sumas;
    pthread_mutex_t puedos_acceder_posicion;
} datos_compartidos_t;

// Datos únicos para cada un de los threads.
typedef struct private_data {
    int64_t num;
    datos_compartidos_t* shared_data;
} datos_privados_t;


arreglo_dinamico_t* calcular(arreglo_dinamico_t* datos, uint64_t thread_count);


void generarPrimos(primos_t* primos, int64_t contenido_nodo_arreglo);


void agreagarSumas(nodoNumero_t* num
    , datos_compartidos_t* shared_data);

bool esPar(int64_t num);

void* sumaPar(void* number_data);

void* sumaImpar(void* number_data);

void crear_threads(nodoNumero_t* num, pthread_t* threads
    , datos_compartidos_t* shared_data
    , datos_privados_t* private_data
    , void* trabajo);

#endif  // HILOS_H
