#include <sumas.h>

typedef struct sumas{
    char* entrada;
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

bool es_fuerte(array_uint64_t suma, uint64_t numero1, uint64_t numero2);

bool es_debil(array_uint64_t suma, uint64_t numero1, uint64_t numero2,
             uint64_t numero3);


uint64_t get_valores(char* entrada);

array_uint64_t generar_numeros_primos(uint64_t numero);

array_uint64_t obtener_conjetura_fuerte(array_uint64_t numeros_primos,
                                        uint64_t numero);

array_uint64_t obtener_conjetura_debil(array_uint64_t numeros_primos,
                                        uint64_t numero);
                                    
array_uint64_t obtener_sumas(bool es_par, uint64_t numero, 
                            array_uint64_t numeros_primos);

uint64_t obtener_conteo(bool es_par, array_uint64_t suma);

sumas_t* sumas_create(char* entrada){
    sumas_t* sumas = (sumas_t*) calloc(1, sizeof(sumas_t));
    sumas -> entrada = entrada;
    sumas -> valor = 0;
    sumas -> contar = 0;
    sumas -> es_valido = validaciones(sumas -> entrada);
    sumas -> es_positivo = false;
    sumas -> es_negativo = false;
    sumas -> es_par = false;
    array_uint64_init(&sumas -> numeros_primos);
    array_uint64_init(&sumas -> suma);
    if (sumas -> es_valido){
        sumas -> valor = get_valores(sumas -> entrada);
        sumas -> es_par = validar_par(sumas -> entrada);
        sumas -> es_negativo = validar_negativo(sumas -> entrada);
    }
    return sumas;
}