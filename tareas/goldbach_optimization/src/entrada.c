/**
 * Copyright [2022] Daniel Lizano UCR
 * Calse encargada de recibir el archivo de texto y leerlo
 */
#include <assert.h>
#include <stdio.h>
#include <errno.h>

#include "arreglo_de_datos.h"
#include "arreglo_de_sumas.h"
#include "entrada.h"


void get_file(FILE* entrada,  arreglo_dinamico_t* numeros) {
    assert(entrada);
    int64_t valor;
    // Termina si encuentra un caracter o fin de linea
    while (fscanf(entrada, "%ld", &valor) == 1) {
        if (errno == ERANGE) {  // Cuando el num está fuera de rango.
            arreglo_dinamico_append(numeros, valor, FUERA_DE_RANGO);
        } else if (valor > 0) {  // Si el num es positivo.
            arreglo_dinamico_append(numeros, valor, SIN_SUMAS);
        } else {
            arreglo_dinamico_append(numeros, valor, COMPLETO);
        }
        errno = 0;
    }
}
