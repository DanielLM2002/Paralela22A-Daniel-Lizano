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

void arreglo_primos_init(primos_t* numero_primo);

void destroy_primos(primos_t* numero_primo);

int64_t primos_agregar(primos_t* numero_primo, int64_t value);

int64_t distribuir_mapeo_dinamico(int64_t hilo, int64_t cantidad_datos
    , int64_t cantidad_threads);

#endif  // ASIGNADOS_H
