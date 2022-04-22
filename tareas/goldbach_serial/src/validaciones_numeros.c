#include "validaciones_numeros.h"



bool validar_negativo(uint64_t numero){
    return numero > 0 ? true : false;
}

bool validar_par(uint64_t numero){
    return (numero % 2 == 0) ? true : false;
}

bool es_valido(uint64_t numero){

}

uint64_t get_valores(char* dato){//guardamos dato como entero de 64 bits
    uint64_t valor = (uint64_t) atoi(dato);
    return valor;
}

bool validar_primo(uint64_t numero){
    
    if (numero == 0 || numero == 1 || numero == 4) return false;
    for (int x = 2; x < numero / 2; ++x ){
        if (numero % x == 0) return false;
    }
    return true;

}
