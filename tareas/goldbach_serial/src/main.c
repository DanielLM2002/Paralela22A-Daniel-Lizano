/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de correr el programa
 * 
 */
#include "entrada.h"
int main(void) {
    entrada_t entry;
    entrada_init(&entry);
    run(&entry);
    return entry.error;
}
