/**
 * Copyright [2022] Daniel Lizano UCR
 */
#include <assert.h>
#include <stdio.h>
#include <errno.h>

#include "arreglo_de_datos.h"
#include "arreglo_de_sumas.h"
#include "entrada.h"

/* -------------------------------*/
/**
 * @brief Recibe la file estandar y guarda todos los datos en un
 * arreglo dinamico.
 * Detiene la lectura si se encuentra con un caracter.
 */
/* ---------------------------------*/
void read_file(FILE* file, numbers_t* numbers) {
    assert(file);
    int64_t value;
    // Termina si encuentra un caracter o fin de linea
    while (fscanf(file, "%ld", &value) == 1) {
        if (errno == ERANGE) {  // Cuando el number está fuera de rango.
            arreglo_add_number(numbers, value, FUERA_DE_RANGO);
        } else if (value > 0) {  // Si el number es positivo.
            arreglo_add_number(numbers, value, SIN_SUMAS);
        } else {
            arreglo_add_number(numbers, value, COMPLETO);
        }
        errno = 0;
    }
}
