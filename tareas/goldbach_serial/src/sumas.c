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


bool validaciones(char* entrada);

bool validar_negativo(char* entrada);

bool validar_par(char* entrada);

bool validar_primo(char* entrada);

bool es_fuerte(array_uint64_t suma, u_int64_t numero1, u_int64_t numero2);

bool es_debil(array_uint64_t suma, uint64_t numero1, uint64_t numero2,
                uint64_t numero3);

uint64_t get_valor(char* entrada);