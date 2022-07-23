/**
 * Copyright [2022] Daniel Lizano UCR
 * clase main encargada de invocar todo el programa
 */
#include <unistd.h>
#include <inttypes.h>
#include <pthread.h>
#include "arreglo_de_datos.h"
#include "hilos.h"
#include "sumas.h"
#include "entrada.h"

int main(int argc, char* argv[]) {
    // Define de donde se reciben los numeros y donde imprimirlos
    FILE* entrada = stdin;
    FILE* salida = stdout;
    // Define la cantidad de threads con los que trabajar
    uint64_t thread_count = sysconf(_SC_NPROCESSORS_ONLN);
    if (argc == 2) {
        // Guarda el valor dado por el usuario en thread_count
        if (sscanf(argv[1], "%" SCNu64, &thread_count) == 1) {
        } else {
            // ERROR 11 = numero de threads invalido
            return 11;
        }
    }
    arreglo_dinamico_t datos;
    arreglo_dinamico_init(&datos);
    get_file(entrada, &datos);
    calcular(&datos, thread_count);
    imprimir(salida, &datos);
    arreglo_dinamico_destroy(&datos);
    return 0;
}

