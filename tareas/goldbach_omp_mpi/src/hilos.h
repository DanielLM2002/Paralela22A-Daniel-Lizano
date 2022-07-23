/**
 * Copyright [2022] Daniel Lizano UCR
 * Calse encargada de crear los hilos y distribuir el trabajo
 */

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

/**
 * @brief Calcula la cantida de sumas de numeros primos que
 * pueden dar como resultado un num.
 *
 * @param datos Recibe un arreglo de objetos con un conjunto de datos
 * para los cuales calcular sus sumas.
 * @param thread_count Numero de threas que crear para realizar
 * las operaciones.
 *
 * @return Retorna un arreglo con todas las sumas que generan cada valor.
 */
arreglo_dinamico_t* calcular(arreglo_dinamico_t* datos, uint64_t thread_count);

/**
 * @brief Genera numeros primos del 2 hasta un num dado contenido_nodo_arreglo.
 *
 * @param primos Dirección al arreglo donde agregar los primos.
 * @param contenido_nodo_arreglo num contenido_nodo_arreglo hasta cual probar si hay primos.
 */
void generarPrimos(primos_t* primos, int64_t contenido_nodo_arreglo);

/**
 * @brief Agreaga las sumas necesarias a un num.
 *
 * @param num Dirección al num donde agregar las sumas.
 * @param primos dirección al arreglo con los num primos ha utilizar.
 */
void agreagarSumas(nodoNumero_t* num
    , datos_compartidos_t* shared_data);

/**
 * @brief Verifica si un num es par o no.
 *
 * @param num Numero ha verificar.
 *
 * @return true: si es par, false: si no es par.
 */
bool esPar(int64_t num);

/**
 * @brief Genera las sumas de goldbach para un num par.
 *
 * @param num Dirección al num donde agregar las sumas.
 * @param primos dirección al arreglo con los num primos ha utilizar.
 * @param thread_count Numero de threas que crear para realizar
 * las operaciones.
 */
void* sumaPar(void* number_data);

/**
 * @brief Genera las sumas de goldbach para un num impar.
 *
 * @param num Dirección al num donde agregar las sumas.
 * @param primos dirección al arreglo con los num primos ha utilizar.
 * @param thread_count Numero de threas que crear para realizar
 * las operaciones.
 */
void* sumaImpar(void* number_data);

/**
 * @brief  Genera los hilos para las tareas asignadas.
 * 
 * @param num 
 * @param threads 
 * @param shared_data 
 * @param private_data 
 * @param trabajo 
 */
void crear_threads(nodoNumero_t* num, pthread_t* threads
    , datos_compartidos_t* shared_data
    , datos_privados_t* private_data
    , void* trabajo);

#endif  // HILOS_H
