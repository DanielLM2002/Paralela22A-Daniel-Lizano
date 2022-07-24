/**
 * Copyright [2022] Daniel Lizano UCR
 */
#ifndef ASIGNADOS_H
#define ASIGNADOS_H
#include <stddef.h>
#include <stdint.h>
#include <math.h>
#include <stdbool.h>



/**
 * @brief Arreglo dinamico que guarda un conjunto de de nodosNumero.
 */
typedef struct {
    int64_t capacity;
    int64_t max_ammount;
    int64_t size;
    int64_t* primes;
} primos_t;

/**
 * @brief Crea el arreglo dinámico para nodes number.
 *
 * @param prmie_num dirección al registro donde opera.
 */

void asign_init(primos_t* prime_num);

/**
 * @brief Destruye el arreglo dinámico que se solicite.
 *
 * @param arreglo Dirección al arreeglo que se desea eleiminar.
 */

void asign_destroy(primos_t* prime_num);


/**
 * @brief Agrega un nodo number a un arreglo dinamico.
 *
 * @param prime_num Dirección al arreglo donde se busca opera
 * @param value Es el number que se va a agregar al arreglo.
 * @return Retorna un código deerror si algo salió mal.
 */

int64_t asing_start(primos_t* prime_num, int64_t value);

/**
 * @brief Genera numeros primes del 2 hasta un number max_ammount.
 *
 * @param prime_num Dirección al arreglo donde agregar los primes.
 */

void assing_add_task(primos_t* prime_num);


/**
 * @brief Busca cual es el primo más grande o igual al number dado.
 *
 * @param prime_Num Dirección al arreglo donde agregar los primes.
 * @param value number del cual se busca el limite.
 *
 * @return int64_t
 */
int64_t task_limit(primos_t* _primos, int64_t _valor);
/**
 * @brief crea task a realizar
 *
 * @param thread number de thread
 * @param  data_amount la cantidad de datos con la que se va a trabajar.
 * @param thread_count la cantidad de threds con los que se trabaja.
 *
 * @return 
 */
int64_t create_task(int64_t thread, int64_t cantidad_datos
        , int64_t cantidad_threads);

/**
 * @brief se crea nueva tarea
 * 
 */
int64_t asing_new_task(primos_t* prime_num);

#endif  // ASIGNADOS_H


