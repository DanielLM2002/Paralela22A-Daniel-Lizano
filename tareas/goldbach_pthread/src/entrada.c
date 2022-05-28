/**
 * Copyright [2022] Daniel Lizano
 * Clase encargada de recibir las sumas y
 * desplegarlas en la pantalla para el usuario
 * 
 */
#include <time.h>
#include "entrada.h"
#include "sumas.h"

int entrada_ejecutar(int argc, char* argv[]) {
  int error = EXIT_SUCCESS;
  
  struct timespec start_time, finish_time;
  clock_gettime(CLOCK_MONOTONIC, &start_time);

  uint64_t total_threads = entrada_validacion_entrada(argc, argv);
  if (total_threads > 0) {
    arreglo_t* cola = (arreglo_t*)calloc(1, sizeof(arreglo_t));
    arreglo_init(cola);
    error = entrada_extraer_archivo(cola);
    error = goldbach_suma_total(cola, total_threads);
    if (error == EXIT_SUCCESS) {
      interfaz_imprimir(cola);
    } else {
      fprintf(stderr, "ERROR: there was an unknown error\n");
    }
    arreglo_destruir(cola);
    free(cola);
  } else {
    error = EXIT_FAILURE;
  }
  clock_gettime(CLOCK_MONOTONIC, &finish_time);
  double tiempo = finish_time.tv_sec - start_time.tv_sec + 
  (finish_time.tv_nsec - start_time.tv_nsec) / 10000000000.0;
  printf("Duracion: %.9lfs\n", tiempo);
  return error;  
}

int entrada_extraer_archivo(arreglo_t * cola) {
  int64_t valor_actual = 0;
  int error = EXIT_SUCCESS;
  int invalido = 0;
  while (feof(stdin) == 0) {
    if (fscanf(stdin, "%ld", &valor_actual) == 1) {
      entrada_validar(&invalido);
      error = arreglo_posible_insertar(cola, valor_actual, invalido);
      invalido = 0;
    } else {
      ignorar_linea();
      valor_actual = 0;
      error = arreglo_insertar(cola, valor_actual, 1);
    }
  }
  return error;
}

void ignorar_linea() {
  char ignorar = '\0';
  while (ignorar != EOF && ignorar != '\n') {
    ignorar = fgetc(stdin);
  }
}

void entrada_validar(int* invalido) {
  if (errno == ERANGE) {
    *invalido = 1;
    clearerr(stdin);
    errno = 0;
  }
}


