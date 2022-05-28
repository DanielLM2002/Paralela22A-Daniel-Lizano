/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de realizar las sumas y enviarlas a 
 * la clase entrada
 * 
 */
#include "sumas.h"
#include <math.h>
/**
 * @brief revisar si hay espacio en memoria para realizar las operaciones
 * y realizar todas las operaciones 
 * 
 * @param cola 
 * @return int 
 */
int goldbach_suma_total(arreglo_t* cola, uint64_t hilos) {
  int error = EXIT_SUCCESS;
  if (cola->tamano - 1 > 0) {
    shared_data_t* shared_data = pthread_init_shared_data(cola, hilos);
    error = pthread_crear_hilos(shared_data);
    shared_data->hilos = 0;
    shared_data->cola = NULL;
    free(shared_data);
  }
  return error;
}
/**
 * @brief revisar si el numero a usar es primo 
 * 
 * @param numero 
 * @return true 
 * @return false 
 */
bool goldbach_es_primo (int64_t numero) {
  bool resultado = false;
  if (numero >= 2) {
    resultado = true;
    int64_t limite = numero-1;
    for (int i = 2; i <= limite; i++) {
      if (numero % i == 0) {
          resultado = false;
      } 
    }
  }
  return resultado;
}
/**
 * @brief revisar si el numero es par
 * 
 * @param numero 
 * @param cola_goldbach 
 * @return int 
 */
int goldbach_par(int64_t numero, arreglo_t* cola_goldbach) {
  int error = EXIT_SUCCESS;

  for (int64_t i = 2; i < numero; i++) {
    if (goldbach_es_primo(i) == true) {
      for (int64_t j = 0; j < numero; j++) {
        if (i + j == numero && goldbach_es_primo(j) == true) {
          error = arreglo_posible_insertar(cola_goldbach, i , 0);
          error = arreglo_posible_insertar(cola_goldbach, j, 0);
        }
      }
    }
  }

  return error;

}

/**
 * @brief revisar si el numero es impar
 * 
 * @param numero 
 * @param cola_goldbach 
 * @return int 
 */
int goldbach_impar(int64_t numero, arreglo_t* cola_goldbach) {
  int error = EXIT_SUCCESS;

  for (int64_t i = 2; i < numero; i++) {
    if (goldbach_es_primo(i) == true) {
      for (int64_t j = 2; j < numero; j++) {
        if (goldbach_es_primo(j) == true) {
          for (int64_t k = 2; k < numero; k++) {
            if (i + j + k == numero && goldbach_es_primo(k)) {
                if (i <= j && i <= k && j <= k) {
                 error = arreglo_posible_insertar(cola_goldbach, i , 0);
                 error = arreglo_posible_insertar(cola_goldbach, j, 0);
                 error = arreglo_posible_insertar(cola_goldbach, k , 0);
                } 
            }
          }
        }
      }
    }
  }

  return error;

}
/**
 * @brief enciar la suma del numero
 * 
 * @param numero 
 * @param cola_goldbach 
 * @return int 
 */
int goldbach_suma_numero(int64_t numero, arreglo_t* cola_goldbach) {
  
  if (numero % 2 == 0) {
    return goldbach_par(numero, cola_goldbach);
  } else {
    return goldbach_impar(numero, cola_goldbach);
  }

}
