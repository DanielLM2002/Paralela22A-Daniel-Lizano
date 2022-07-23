/**
 * Copyright [2022] Daniel Lizano UCR
 */
#include <stdio.h>

#include "hilos.h"
#include "arreglo_de_datos.h"

void print(FILE* output, numbers_t* numbers) {
    numberNode_t currentNumber;
    for (int64_t index = 0; index < (int64_t)numbers->size; index++) {
        currentNumber = numbers->nodes[index];
        if (currentNumber.validation == FUERA_DE_RANGO) {
            // Imprime NA por estar fuera de rango.
            fprintf(output, "NA\n");
        } else if (currentNumber.validation == MENOR_A_5) {
            // Solo imprime el number y NA.
            fprintf(output, "%ld: NA\n", currentNumber.number);
        } else if (currentNumber.validation == SIN_SUMAS) {
            // Solo imprime la cantidad de sums.
            fprintf(output, "%ld: %ld sums\n", currentNumber.number
                    , currentNumber.sums->size);
        } else {
            // Imprime la cantidad de sums y cuales son
            fprintf(output, "%ld: %ld sums: ", currentNumber.number
                    , currentNumber.sums->size);
            print_sums(output, &currentNumber);
        }
    }
}

/* -------------------------------*/
/**
 * @brief Imprime un conjunto de sums.
 *
 * @param sums Dirección a una arreglo dinamico con las sums.
 */
/* ---------------------------------*/
void print_sums(FILE* output, numberNode_t* node) {
    for (int64_t index = 0; index < (int64_t)node->sums->size; index++) {
        sumNode_t current_sums = node->sums->sumNode[index];
        fprintf(output, "%s", (index > 0)? ", ":"");
        fprintf(output, "%ld + ", current_sums.state1);
        fprintf(output, "%ld", current_sums.state2);
        if (current_sums.state3 > 0) {
            fprintf(output, " + %ld", current_sums.state3);
        }
    }
    fprintf(output, "\n");
}
