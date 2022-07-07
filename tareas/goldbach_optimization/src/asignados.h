/**
 * Copyright [2022] Daniel Lizano UCR
 * Calse encargada de recibir el arreglo con las sumas y 
 * distribuir el trabajo
 */
#ifndef ASIGNADOS_H
#define ASIGNADOS_H
#include <stddef.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    int64_t tamanio;
    int64_t capacidad;
    int64_t* primos;
} primos_t;

/**
 * @brief Crea el arreglo dinámico para nodos num.
 *
 * @param arreglo dirección al registro donde opera.
 */
void arreglo_primos_init(primos_t* numero_primo);

/**
 * @brief Destruye el arreglo dinámico que se solicite.
 *
 * @param arreglo Dirección al arreeglo que se desea eleiminar.
 */
void destroy_primos(primos_t* numero_primo);

/**
 * @brief Agrega un nodo num a un arreglo dinamico.
 *
 * @param numero_primo Dirección al arreglo donde se busca opera
 * @param value Es el num que se va a agregar al arreglo.
 * @return Retorna un código deerror si algo salió mal.
 */
int64_t primos_agregar(primos_t* numero_primo, int64_t value);

/**
 * @brief Distribucion de tareas asignadas para los hilos en 
 * el mapeo dinamico
 * 
 * @param hilo 
 * @param cantidad_datos 
 * @param cantidad_threads 
 * @return int64_t 
 */
int64_t distribuir_mapeo_dinamico(int64_t hilo, int64_t cantidad_datos
    , int64_t cantidad_threads);

#endif  // ASIGNADOS_H
