/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de correr el programa
 * 
 */
#include "entrada.h"
int main(void) {
    interfaz_t entrada;
    entrada_init(&entrada);
    entrada_ejecutar(&entrada);
    return entrada.error;
}
