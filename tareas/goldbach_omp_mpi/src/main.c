/**
 * Copyright [2022] Daniel Lizano UCR
 */
#include <unistd.h>
#include <inttypes.h>
#include <pthread.h>
#include <omp.h>

#include "arreglo_de_datos.h"
#include "sumas.h"
#include "entrada.h"
#include "hilos.h"

int main(int argc, char* argv[]) {
    // Define de donde se reciben los numeros y donde imprimirlos
    FILE* file = stdin;
    FILE* output = stdout;
    // Define la cantidad de threads con los que trabajar
    uint64_t thread_count = sysconf(_SC_NPROCESSORS_ONLN);
    if (argc == 2) {
        // Guarda el valor dado por el usuario en thread_count
        if (sscanf(argv[1], "%" SCNu64, &thread_count) == 1) {
        } else {
            // Numeors de threads invalido
            return 11;
        }
    }
    numbers_t data;
    arreglo_init(&data);
    read_file(file, &data);
    calculate(&data, thread_count);
    print(output, &data);
    arreglo_destroy(&data);
    return 0;
}

