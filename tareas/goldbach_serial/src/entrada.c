/**
 * Copyright [2022] Daniel Lizano
 * Clase encargada de recibir las sumas y
 * desplegarlas en la pantalla para el usuario
 * 
 */
#include "entrada.h"
#include "sumas.h"
/**
 * @brief inicializacion de la estructura entrada
 * 
 * @param interfaz 
 */
void entrada_init(interfaz_t* interfaz) {
  interfaz->error = EXIT_SUCCESS;
}
/**
 * @brief Main driver de todo el programa
 * 
 * @param interfaz 
 * @return int 
 */
int entrada_ejecutar(interfaz_t* interfaz) {
  arreglo_t cola;  // cola para guardar numeros del archivo 
  arreglo_init(&cola);

   
  entrada_get_file(interfaz, &cola);

  // una vez guardada procedemos a hacer las sumas de goldbach
  goldbach_suma_total(&cola);

  if (interfaz ->error == 0) {
    // se imprime el resultado si no hay errores 
    entrada_imprimir(&cola);
  } else {
    fprintf(stderr, "Hubo un error con el programa");
  }

  // se libera la memoria 
  arreglo_destruir(&cola);
  return interfaz->error;
}
/**
 * @brief getter para obtener archivo desde la entrada estandar
 * 
 * @param interfaz 
 * @param cola 
 */
void entrada_get_file(interfaz_t * interfaz, arreglo_t * cola) {
  int64_t valor_actual = 0;
  int invalido = 0;
  while (feof(stdin) == 0) {
    if (fscanf(stdin, "%ld", &valor_actual) == 1) {
      entrada_validate(&invalido);
      interfaz->error = arreglo_posible_insertar(cola, valor_actual, invalido);
      invalido = 0;
    } else {
      ignorar_linea();
      valor_actual = 0;
      interfaz->error = arreglo_insertar(cola, valor_actual, 1);
    }
  }
}
/**
 * @brief metodo para ignorar lineas vacias
 * 
 */
void ignorar_linea() {
  char ignorar = '\0';
  while (ignorar != EOF && ignorar != '\n') {
    ignorar = fgetc(stdin);
  }
}
/**
 * @brief revisar si el archivo de entrada y sus items son validos
 * 
 * @param invalido 
 */
void entrada_validate(int * invalido) {
  if (errno == ERANGE) {
    *invalido = 1;
    clearerr(stdin);
    errno = 0;
  }
}
/**
 * @brief metodo para realizar la impresion del resultado
 * 
 * @param actual 
 * @param valor 
 */
void entrada_imprimir_goldbach(arreglo_nodo_t * actual, int64_t valor) {
  int64_t posicion = 0;
  int64_t numero = 0;
  arreglo_nodo_t* actual_goldbach = arreglo_nodo_conseguir_cola_goldbach(actual)->primero;
  bool es_impar = true;
  if (valor % 2 == 0) {
    es_impar = false;
  }
  int64_t contador = 0;
  while(actual_goldbach) {
    posicion = arreglo_nodo_conseguir_posicion(actual_goldbach);
    numero = arreglo_nodo_conseguir_valor(actual_goldbach);
    if (posicion > 0) {
      fprintf (stdout, "%ld + ", numero);
      numero = 0;
      contador++;
      if (es_impar == true && contador == 3) {
        fprintf(stdout, ", ");
        contador = 0;
      } else if (es_impar == false && contador == 2){
        fprintf(stdout, ", ");
        contador = 0;
      }
    } else {
      fprintf(stdout, "%ld", numero);
    }
    actual_goldbach = arreglo_nodo_conseguir_siguiente(actual_goldbach);
  }
}
/**
 * @brief realizar impresion de las sumas
 * 
 * @param cola 
 */
void entrada_imprimir(arreglo_t * cola) {
  arreglo_nodo_t* actual = cola->primero;
  int64_t valor = 0;
  int64_t valor_positivo = 0;

  while (actual) {
    valor = arreglo_nodo_conseguir_valor(actual);
    if (arreglo_nodo_conseguir_validez(actual)) {
      fprintf(stdout, "%ld: NA\n", valor);
    }
    if (valor >= 0 && valor <= 5) {
        fprintf(stdout,"%ld: NA\n", valor);
    }
    if (valor > 5 || valor < -5) {
       fprintf(stdout,"%ld: ", valor);
      entrada_conseguir_sumas(actual, valor);
      if (valor < -5) {
        valor_positivo = valor + (valor * -2);
        entrada_imprimir_goldbach(actual, valor_positivo);
      }
      fprintf(stdout, "\n");
    }
    actual = arreglo_nodo_conseguir_siguiente(actual);
  }
}
/**
 * @brief metodo linker para obtener sumas 
 * 
 * @param actual 
 * @param valor 
 */
void entrada_conseguir_sumas(arreglo_nodo_t* actual, int64_t valor) {
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
      if (contador == 2) {
        contador = 0;
        contador_total++;
      }
    }
    actual_goldbach = arreglo_nodo_conseguir_siguiente(actual_goldbach);
  }
  fprintf(stdout, "%i sums: ", contador_total);
}


