#include "validaciones_numeros.h"

bool validar_negativo(uint64_t numero){
    return numero > 0 ? true : false;
}

bool validar_par(uint64_t numero){
    return (numero % 2 == 0) ? true : false;
}

uint64_t get_valores(char* dato){//guardamos dato como entero de 64 bits
    uint64_t valor = (uint64_t) atoi(dato);
    return valor;
}
