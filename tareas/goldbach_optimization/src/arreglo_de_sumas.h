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

sumas_logradas* arreglo_sumas_init(void);

/**
 * @brief Destruye el arreglo dinámico que se solicite.
 *
 * @param sums Dirección al arreeglo que se desea eleiminar.
 * @param valid_num TRUE: es un arreglo de sumas_logradas por lo que no se debe
 * eliminar la dirección del arreglo que semando
 */

void sumas_delete(sumas_logradas* sums, bool valid_num);

int64_t sumas_push(sumas_logradas* arreglo);

int64_t sumas_Add(sumas_logradas* sums, int64_t digito
    , int64_t digito2, int64_t digito3);

#endif  // ARREGLO_H
