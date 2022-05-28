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
    double limite = sqrt((double)(numero));
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
  if (numero < -5) {
    numero = numero + (numero * -2);
  }
  int64_t numero_aux = 0;
  for (int64_t i = 2; i < numero; i++) {//si no funca cambiar por int64
    if (goldbach_es_primo(i) == true) {
      numero_aux = numero - i;
      if (i + numero_aux == numero &&
       goldbach_es_primo(numero_aux) == true && i < numero_aux) {
         error = arreglo_posible_insertar(cola_goldbach, i, 0);
         error = arreglo_posible_insertar(cola_goldbach, numero_aux, 0);
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
  if (numero < -5) {
    numero = numero + (numero * -2);
  }
  int64_t numero_temp = 0;
  for (int64_t i = 2; i < numero; i++) {
    if (goldbach_es_primo(i) == true && i != numero) {
      for (int64_t j = 2; j < numero; j++) {
        if (goldbach_es_primo(j) == true && j != numero) {
          numero_temp = numero - (j + i);
          if (i + j + numero_temp == numero && 
           goldbach_es_primo(numero_temp)) {
            if (i <= j && i <= numero_temp && j <= numero_temp) {
              error = cola_posible_insertar(cola_goldbach, i, 0);
              error = cola_posible_insertar(cola_goldbach, j, 0);
              error = cola_posible_insertar(cola_goldbach, numero_temp, 0);
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

void* goldbach_cola_secundaria(void* cola) {
  private_data_t* private_data = (private_data_t*)cola;
  arreglo_nodo_t* actual = private_data->primero;
  while (actual) {
    
  }
}
