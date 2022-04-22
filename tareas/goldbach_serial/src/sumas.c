#include <sumas.h>

typedef struct sumas{
    bool es_valido;
    bool es_negativo;
    bool es_positivo;
    bool es_par;
    uint64_t valor;
    uint64_t contar;
    array_uint64_t numeros_primos;
    array_uint64_t suma;
} sumas_t;