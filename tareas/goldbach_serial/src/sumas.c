#include "sumas.h"
typedef struct sumas{
    char* dato;
    uint64_t valores;
    uint64_t contar;
    array_uint64_t* orden;
    array_uint64_t* numeros_primos;
    array_uint64_t* suma;
} sumas_t;


sumas_t* sumas_create(char* entrada){
    //iniciar campos de sumas
    sumas_t* sumas = (sumas_t*) calloc(1, sizeof(sumas_t));
    sumas -> dato = entrada;
    sumas -> valores = 0;
    sumas -> contar = 0;
    array_uint64_init(&sumas -> numeros_primos);
    array_uint64_init(&sumas -> suma);
    return sumas; //retorno de la esctructura
    
}

uint64_t valor = 0;
uint64_t numero_entradas = 0;
uint64_t tamanio = 1024;
//uint64_t *entrada = (uint64_t *) malloc(tamanio * sizeof(entrada));


void leer_archivo(){
    while(fscanf(stdin, "%ld", &valor)==1){
    entrada[numero_entradas] = valor;
    numero_entradas++;
}
}


