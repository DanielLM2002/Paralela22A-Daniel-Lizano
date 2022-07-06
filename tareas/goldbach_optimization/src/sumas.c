#include <stdio.h>

#include "sumas.h"


void imprimirSumas(FILE* salida, nodoNumero_t* nodo);

void imprimir(FILE* salida, arreglo_dinamico_t* numeros) {
    nodoNumero_t numero_actual;
    for (int64_t index = 0; index < (int64_t)numeros->capacidad; index++) {
        numero_actual = numeros->nodos[index];
        if (numero_actual.bander == FUERA_DE_RANGO) {
            // Imprime NA por estar fuera de rango.
            fprintf(salida, "NA\n");
        } else if (numero_actual.bander == MENOR_A_5) {
            // Solo imprime el num y NA.
            fprintf(salida, "%ld: NA\n", numero_actual.num);
        } else if (numero_actual.bander == SIN_SUMAS) {
            // Solo imprime la cantidad de sumas.
            fprintf(salida, "%ld: %ld sums\n", numero_actual.num
                    , numero_actual.sumas->capacidad);
        } else {
            // Imprime la cantidad de sumas y cuales son
            fprintf(salida, "%ld: %ld sums: ", numero_actual.num
                    , numero_actual.sumas->capacidad);
            imprimirSumas(salida, &numero_actual);
        }
    }
}


void imprimirSumas(FILE* salida, nodoNumero_t* nodo) {
    for (int64_t index = 0; index < (int64_t)nodo->sumas->capacidad; index++) {
        nodoSuma_t suma_actual = nodo->sumas->nodosSuma[index];
        fprintf(salida, "%s", (index > 0)? ", ":"");
        fprintf(salida, "%ld + ", suma_actual.cabeza);
        fprintf(salida, "%ld", suma_actual.cola);
        if (suma_actual.auxiliar > 0) {
            fprintf(salida, " + %ld", suma_actual.auxiliar);
        }
    }
    fprintf(salida, "\n");
}
