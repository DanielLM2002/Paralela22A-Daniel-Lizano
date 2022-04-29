#ifndef ARREGLO_DE_DATOS_H
#define ARREGLO_DE_DATOS_H
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <stddef.h>

typedef struct arreglo_nodo arreglo_nodo_t;

typedef struct arreglo_de_datos{
    arreglo_nodo_t* cabeza;
    arreglo_nodo_t* cola;
    uint64_t* elemento;
} arreglo_de_datos_t;
/**
 * @brief inicia el arreglo a usar en el programa  
 * @details realiza el assert para poder iniciar el arreglo 
 * 
 * @param arreglo 
 */
void arreglo_init(arreglo_de_datos_t* arreglo);

/**
 * @brief obtiene los valores de el arreglo
 * 
 * @param arreglo 
 * @return int64_t 
 */
int64_t get_value_arreglo(arreglo_nodo_t* arreglo);

/**
 * @brief obtiene la posicion del actual del nodo del arreglo
 * 
 * @param nodo 
 * @return int64_t 
 */
int64_t get_posicion_arreglo(arreglo_nodo_t* nodo);

/**
 * @brief obtener el siguiente nodo
 * 
 * @param nodo 
 * @return arreglo_nodo_t* 
 */
arreglo_nodo_t* get_siguiente(arreglo_nodo_t* nodo);

/**
 * @brief method para poder insertar un char valido 
 * dento del arreglo
 * 
 * @param arreglo 
 * @param value 
 * @param valid 
 * @return int 
 */
int insert(arreglo_de_datos_t* arreglo, int64_t value, int valid);

/**
 * @brief obtiene el arreglo que sera usado en el sistema de suma 
 * @param nodo 
 * @return arreglo_de_datos_t* 
 */
arreglo_de_datos_t* get_arreglo_sumas_goldbach(arreglo_nodo_t* nodo);

/**
 * @brief se encarga de buscar el valor deseado dentro del arreglo
 * 
 * @param arreglo 
 * @param searching 
 * @return arreglo_nodo_t* 
 */
arreglo_nodo_t* search(arreglo_de_datos_t* arreglo, int64_t value);

/**
 * @brief se encarga de destruir unicamente el nodo actual en el
 * se encuentra
 * 
 * @param nodo 
 */
void nodo_destroy(arreglo_nodo_t* nodo);

/**
 * @brief se encarga de destruir el arreglo completamente 
 * 
 * @param arreglo 
 */
void arreglo_destroy(arreglo_de_datos_t* arreglo);

/**
 * @brief se encarga de verificar que el item del nodo sea valido
 * 
 * @param nodo 
 * @return int 
 */
int nodo_validate(arreglo_nodo_t* nodo);

/**
 * @brief se encarga de dar la validacion de que es posible meterlo en
 * el arreglo
 * 
 * @param arreglo 
 * @param value 
 * @param valid 
 * @return int 
 */
int array_insertion (arreglo_de_datos_t* arreglo, int64_t value, int valid);
#endif