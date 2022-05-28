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
    error = entrada_get_file(cola);
    error = goldbach_suma_total(cola, total_threads);
    if (error == EXIT_SUCCESS) {
      entrada_imprimir(cola);
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

int entrada_get_file(arreglo_t * cola) {
  int64_t valor_actual = 0;
  int error = EXIT_SUCCESS;
  int invalido = 0;
  while (feof(stdin) == 0) {
    if (fscanf(stdin, "%ld", &valor_actual) == 1) {
      entrada_validate(&invalido);
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

void entrada_validate(int* invalido) {
  if (errno == ERANGE) {
    *invalido = 1;
    clearerr(stdin);
    errno = 0;
  }
}

void entrada_imprimir_goldbach(arreglo_nodo_t* actual, int64_t valor, int64_t sumas) {
  int64_t numero = 0;
  int64_t contador_sumas = 0;
  arreglo_nodo_t* actual_goldbach = 
    arreglo_nodo_conseguir_cola_goldbach(actual)->primero;
  bool es_impar = true;
  if (valor % 2 == 0) {
    es_impar = false;
  }
  int64_t contador = 0;
  while(actual_goldbach) {
    numero = arreglo_nodo_conseguir_valor(actual_goldbach);
    if (sumas != contador_sumas) {
      fprintf (stdout, "%ld + ", numero);
      numero = 0;
      contador++;
      if (es_impar == true && contador == 3) {
        fprintf(stdout, ", ");
        contador = 0;
        contador_sumas++;
      } else if (es_impar == false && contador == 2){
        fprintf(stdout, ", ");
        contador = 0;
        contador_sumas++;
      }
    } else {
      fprintf(stdout, "%ld", numero);
    }
    actual_goldbach = arreglo_nodo_conseguir_siguiente(actual_goldbach);
  }
}

void entrada_imprimir(arreglo_t* cola) {
  arreglo_nodo_t* actual = cola->primero;
  int64_t valor = 0;
  int64_t valor_positivo = 0;
  int64_t sumas = 0;

  while (actual) {
    valor = arreglo_nodo_conseguir_valor(actual);
    if (arreglo_nodo_conseguir_validez(actual)) {
      fprintf(stdout, "%ld: NA\n", valor);
    }
    if (valor >= -5 && valor <= 5) {
        fprintf(stdout,"%ld: NA\n", valor);
    }
    // Nuestro caso ideal
    if (valor > 5 || valor < -5) {
      fprintf(stdout,"%ld: ", valor);
      sumas = entrada_conseguir_sumas(actual, valor);
      if (valor < -5) {
        valor_positivo = valor + (valor * -2); 
        entrada_imprimir_goldbach(actual, valor_positivo, sumas);
      }
      fprintf(stdout, "\n");
    }
    actual = arreglo_nodo_conseguir_siguiente(actual);
  }
}

int entrada_conseguir_sumas(arreglo_nodo_t* actual, int64_t valor) {
  bool es_impar = true;
  if (valor % 2 == 0) {
    es_impar = false;
  }
  int contador = 0;
  int contador_total = 0;
  arreglo_nodo_t* actual_goldbach = 
    arreglo_nodo_conseguir_cola_goldbach(actual)->primero;
  while (actual_goldbach) {
    if (es_impar) {
      contador++;
      if (contador == 3) {
        contador = 0;
        contador_total++;
      }
    } else {
      contador++;
      if (contador == 2) {
        contador = 0;
        contador_total++;
      }
    }
    actual_goldbach = arreglo_nodo_conseguir_siguiente(actual_goldbach);
  }
  fprintf(stdout, "%i sums: ", contador_total);
  return contador_total;
}

int64_t entrada_validacion_entrada(int argc, char* argv[]) {
  int64_t total_threads = sysconf(_SC_NPROCESSORS_ONLN);
  if (argc == 2) {
    if (sscanf(argv[1], "%ld", &total_threads) == 0 || total_threads < 1
     || errno == ERANGE) {
       if (errno) {
        fprintf(stderr, "ERROR: Exceso de threads\n");
       } else {
        fprintf(stderr,
         "ERROR: numero de threads tiene que ser positivo\n");
       }
      total_threads = 0;
    }
  }
  return (uint64_t) total_threads;
}


