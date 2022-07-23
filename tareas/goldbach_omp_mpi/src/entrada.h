/**
 * Copyright [2022] Daniel Lizano UCR
 * Calse encargada de recibir el archivo de texto y leerlo
 */
#ifndef ENTRADA_H
#define ENTRADA_H

#include <stdio.h>
#include "arreglo_de_datos.h"
/**
 * @brief Permite get_file de la entrada estandar
 *
 * @param entrada Recibe la dirección a la entrada estandar
 *
 * @return Retorna un arreglo dinamico con los datos
 */
void get_file(FILE* entrada, arreglo_dinamico_t* numeros);

#endif  // ENTRADA_H
