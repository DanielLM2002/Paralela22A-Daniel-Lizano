/**
 * Copyright [2022] Daniel Lizano UCR
 */
#ifndef ENTRADA_H
#define ENTRADA_H

#include <stdio.h>

#include "arreglo_de_datos.h"

/* -------------------------------*/
/**
 * @brief Permite read_file de la FILE estandar
 *
 * @param FILE Recibe la dirección a la FILE estandar
 *
 * @return Retorna un arreglo dinamico con los datos
 */
/* ---------------------------------*/
void read_file(FILE* FILE, numbers_t* numbers);

#endif  // ENTRADA_H
