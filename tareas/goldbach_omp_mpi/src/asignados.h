
#ifndef ARREGLO_PRIMOS_H
#define ARREGLO_PRIMOS_H
#include <stddef.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>


/* -------------------------------*/
/**
 * @brief Arreglo dinamico que guarda un conjunto de de nodosNumero.
 */
/* ---------------------------------*/
typedef struct {
    int64_t capacity;
    int64_t max_ammount;
    int64_t size;
    int64_t* primes;
} primos_t;
/* -------------------------------*/
/**
 * @brief Crea el arreglo dinámico para nodes number.
 *
 * @param arreglo dirección al registro donde opera.
 */
/* ---------------------------------*/
void asign_init(primos_t* _primos);
/* -------------------------------*/
/**
 * @brief Destruye el arreglo dinámico que se solicite.
 *
 * @param arreglo Dirección al arreeglo que se desea eleiminar.
 */
/* ---------------------------------*/
void asign_destroy(primos_t* _primos);

/* -------------------------------*/
/**
 * @brief Agrega un nodo number a un arreglo dinamico.
 *
 * @param _primos Dirección al arreglo donde se busca opera
 * @param _valor Es el number que se va a agregar al arreglo.
 * @return Retorna un código deerror si algo salió mal.
 */
/* ---------------------------------*/
int64_t asing_start(primos_t* _primos, int64_t _valor);
/* -------------------------------*/
/**
 * @brief Genera numeros primes del 2 hasta un number max_ammount.
 *
 * @param _primos Dirección al arreglo donde agregar los primes.
 */
/* ---------------------------------*/
void assing_add_task(primos_t* _primos);

/* -------------------------------*/
/**
 * @brief Busca cual es el primo más grande o igual al number dado.
 *
 * @param _primos Dirección al arreglo donde agregar los primes.
 * @param _valor number del cual se busca el limite.
 *
 * @return retorna el indice al limite para el number dado en este arreglo
 * de primes.
 */
/* ---------------------------------*/
int64_t task_limit(primos_t* _primos, int64_t _valor);
/* -------------------------------*/
/**
 * @brief Genera la posición en donde iniciar a calcular utilizar los primes.
 *
 * @param thread number de thread
 * @param  cantidad_datos la cantidad de datos con la que se va a trabajar.
 * @param cantidad_threads la cantidad de threds con los que se trabaja.
 *
 * @return 
 */
/* ---------------------------------*/
int64_t create_task(int64_t thread, int64_t cantidad_datos
        , int64_t cantidad_threads);
#endif  // ARREGLO_PRIMOS_H


