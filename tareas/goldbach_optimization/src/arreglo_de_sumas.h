/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de guardar las sumas para poder distribuirlas y 
 * enviarlas a la clase entrada.
 */
#ifndef ARREGLO_SUMAS_H
#define ARREGLO_SUMAS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    int64_t cabeza;
    int64_t cola;
    int64_t auxiliar;
} nodoSuma_t;

typedef struct {
    size_t tamanio;
    size_t capacidad;
    nodoSuma_t* nodosSuma;
} sumas_logradas;


/**
 * @brief Crea el arreglo dinámico para nodos suma.
 *
 * @param arreglo dirección al registro donde opera.
 */
sumas_logradas* arreglo_sumas_init(void);

/**
 * @brief Destruye el arreglo dinámico que se solicite.
 *
 * @param sums Dirección al arreeglo que se desea eleiminar.
 * @param valid_num TRUE: es un arreglo de sumas_logradas por lo que no se debe
 * eliminar la dirección del arreglo que semando
 */

void sumas_delete(sumas_logradas* sums, bool valid_num);


/**
 * @brief Realiza push del arreglo a la pila.
 *
 * @param arreglo Dirección al arreglo que se desea operar.
 * @return Retorna un código de error si algo salió mal.
 */
int64_t sumas_push(sumas_logradas* arreglo);

/**
 * @brief Agrega un nodo suma a un arreglo dinamico.
 *
 * @param sums Dirección al arreglo donde se busca operar.
 * @param digito Valor del primer dato del objeto.
 * @param digito2 Valor del cola dato del objeto.
 * @param digito3 Valor del auxiliar dato del objeto.
 *
 * @return Retorna un código deerror si algo salió mal.
 */
int64_t sumas_Add(sumas_logradas* sums, int64_t digito
    , int64_t digito2, int64_t digito3);

#endif  // ARREGLO_H
