#include "validaciones_numeros.h"

validaciones_t* validaciones_create(char* entrada){
    //iniciar campos de sumas
    validaciones_t* validaciones = (validaciones_t*) calloc(1, sizeof(validaciones_t));

    validaciones -> entrada = entrada;
    validaciones -> valor = 0;
    validaciones -> contar = 0;
    validaciones -> numero_valido = verificar(validaciones -> entrada);
    validaciones -> es_positivo = false;
    validaciones -> validar_negativo = false;
    validaciones -> validar_par = false;
    array_uint64_init(&validaciones -> numeros_primos);
    array_uint64_init(&validaciones -> suma);
    if (validaciones -> numero_valido){//estado booleano de la estructura
        validaciones -> valor = get_valores(validaciones -> entrada);
        validaciones -> validar_par = validar_par(validaciones -> entrada);
        validaciones -> validar_negativo = validar_negativo(validaciones -> entrada);
    }
    return validaciones; //retorno de la esctructura
}

bool validar_negativo(char* entrada){
    if(entrada[0] == '-')//condicional para detectar negativos
        return true;
    else 
        return false;
}

bool validar_par(char* entrada){
    bool estado = false;
    uint64_t valor = get_valores(entrada);//obtener valor para condicional
    if(valor % 2 == 0)//condicional para definir estado
        estado = true;
    return estado;//retorno de estado booleano
}

uint64_t get_valores(char* entrada){//guardamos entrada como entero de 64 bits
    uint64_t valor = (uint64_t) atoi(entrada);
    return valor;
}
