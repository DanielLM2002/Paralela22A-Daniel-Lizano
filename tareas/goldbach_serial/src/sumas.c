#include "sumas.h"
typedef struct sumas{
    char* dato;
    bool es_valido;
    bool es_negativo;
    bool es_positivo;
    bool es_par;
    uint64_t valor;
    uint64_t contar;
    array_uint64_t* numeros_primos;
    array_uint64_t* suma;
} sumas_t;

array_uint64_t generar_numeros_primos(sumas_t* sumas);

array_uint64_t obtener_conjetura_fuerte(sumas_t* sumas);

array_uint64_t obtener_conjetura_debil(sumas_t* sumas);
                                    
array_uint64_t obtener_sumas(sumas_t* sumas);

uint64_t obtener_conteo(bool es_par, array_uint64_t suma);

sumas_t* sumas_create(char* entrada){
    //iniciar campos de sumas
    sumas_t* sumas = (sumas_t*) calloc(1, sizeof(sumas_t));

    sumas -> dato = entrada;
    sumas -> valor = 0;
    sumas -> contar = 0;
    sumas -> es_valido = validaciones(sumas -> dato);
    sumas -> es_positivo = false;
    sumas -> es_negativo = false;
    sumas -> es_par = false;
    array_uint64_init(&sumas -> numeros_primos);
    array_uint64_init(&sumas -> suma);
    if (sumas -> es_valido){//estado booleano de la estructura
        sumas -> valor = get_valores(sumas -> dato);
        sumas -> es_par = validar_par(sumas -> valor);
        sumas -> es_negativo = validar_negativo(sumas -> valor);
    }
    return sumas; //retorno de la esctructura
}

void sumas_run(sumas_t* sumas){//validacion de campo
    assert(sumas);
    if(sumas -> es_valido){ //valido = true
        return 0;
    }
}