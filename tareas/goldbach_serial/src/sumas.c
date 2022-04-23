#include "sumas.h"
typedef struct sumas{
    char* dato;
    uint64_t valor;
    uint64_t contar;
    array_uint64_t* orden;
    array_uint64_t* numeros_primos;
    array_uint64_t* suma;
} sumas_t;


sumas_t* sumas_create(char* entrada){
    //iniciar campos de sumas
    sumas_t* sumas = (sumas_t*) calloc(1, sizeof(sumas_t));
    sumas -> dato = entrada;
    sumas -> valor = 0;
    sumas -> contar = 0;
    array_uint64_init(&sumas -> numeros_primos);
    array_uint64_init(&sumas -> suma);
    return sumas; //retorno de la esctructura
}

sumas_t* realizar_conjetura_fuerte(int64_t numero){
    if(validar_par(numero)==true){
        
    }
}


