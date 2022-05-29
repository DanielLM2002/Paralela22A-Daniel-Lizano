/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de crear el arreglo en el cual
 * guardaremos los numeros
 * 
 */
#include "arreglo_de_datos.h"
#include <stdio.h>

typedef struct arreglo_nodo {
  // puntero al siguiente nodo
  arreglo_nodo_t* siguiente;

  // Cola que tiene cada nodo individualmente
  arreglo_t cola_goldbach;

  // posicion del valoro en la cola
  int64_t posicion;

  // valor del valoro
  int64_t valor;

  // Indica si el valor es invalido o no
  int validez;
} arreglo_nodo_t;
/**
 * @brief Metodo encargado de iniciar arreglo(cola) que usaremos
 * para guardar los numeros en la ejecucion
 * 
 * @param cola 
 */
void arreglo_init(arreglo_t* cola) {
  assert(cola);
  cola->primero = NULL;
  cola->ultimo = NULL;
  cola->tamanio = 0;
}
/**
 * @brief metodo usado para introducir numeros al arreglo
 * 
 * @param cola 
 * @param valor 
 * @param valido 
 * @return int 
 */
int arreglo_insertar(arreglo_t* cola, int64_t valor, int valido) {
  assert(cola);
  int error = EXIT_SUCCESS;


  arreglo_nodo_t* nuevo_nodo = (arreglo_nodo_t *)
    calloc(1, sizeof(arreglo_nodo_t));
  if (nuevo_nodo) {
    nuevo_nodo->valor = valor;
    nuevo_nodo->validez = valido;
    arreglo_init(&nuevo_nodo->cola_goldbach);
    if (cola->ultimo == NULL) {
      cola->primero = nuevo_nodo;
      cola->ultimo = nuevo_nodo;
    } else {
      cola->ultimo->siguiente = nuevo_nodo;
      cola->ultimo = cola->ultimo->siguiente;
    }
    ++cola->tamanio;
  } else {
    error = EXIT_FAILURE;
    fprintf(stderr, "ERROR: No hay suficiente memoria para agregar el item.");
  }
  return error;
}
/**
 * @brief valida si es posible insertar en arreglo
 * 
 * @param cola 
 * @param valor 
 * @param valido 
 * @return int 
 */
int arreglo_posible_insertar(arreglo_t * cola, int64_t valor, int valido) {
  assert(cola);
  int error = EXIT_SUCCESS;
  error = arreglo_insertar(cola, valor, valido);
  return error;
}
/**
 * @brief metodo encargado de buscar items en el arreglo dinamico
 * 
 * @param cola 
 * @param buscar_valor 
 * @return arreglo_nodo_t* 
 */
arreglo_nodo_t* arreglo_buscar(arreglo_t* cola, int64_t buscar_valor) {
  assert(cola);
  arreglo_nodo_t* actual = cola->primero;
  while (actual && actual->valor != buscar_valor) {
    actual = actual->siguiente;
  }
  return actual;
}
/**
 * @brief metodo para destruir la estructura de arreglo
 * 
 * @param cola 
 */
void arreglo_destruir(arreglo_t* cola) {
  assert(cola);
  arreglo_nodo_t* actual = cola->primero;
  arreglo_nodo_t* temp = NULL;

  while (actual) {
    temp = actual->siguiente;
    arreglo_nodo_destruir(actual);
    actual = temp;
  }
  cola->primero = NULL;
  cola->ultimo = NULL;
}
/**
 * @brief metodo para destruir los nodos
 * 
 * @param nodo 
 */
void arreglo_nodo_destruir(arreglo_nodo_t* nodo) {
  nodo->valor = 0;
  arreglo_destruir(&nodo->cola_goldbach);
  free(nodo);
}
/**
 * @brief metodo getter para obtener valor de un nodo 
 * 
 * @param nodo 
 * @return int64_t 
 */
int64_t arreglo_nodo_conseguir_valor(arreglo_nodo_t* nodo) {
  return nodo->valor;
}
/**
 * @brief conseguir la posicion del nodo
 * 
 * @param nodo 
 * @return int64_t 
 */
int64_t arreglo_nodo_conseguir_posicion(arreglo_nodo_t* nodo) {
  return nodo->posicion;
}
/**
 * @brief conseguir siguiente item en la cola
 * 
 * @param nodo 
 * @return arreglo_nodo_t* 
 */
arreglo_nodo_t* arreglo_nodo_conseguir_siguiente(arreglo_nodo_t* nodo) {
  return nodo->siguiente;
}
/**
 * @brief conseguir toda la estructura de datos para el programa
 * 
 * @param nodo 
 * @return arreglo_t* 
 */
arreglo_t* arreglo_nodo_conseguir_cola_goldbach(arreglo_nodo_t* nodo) {
  return &nodo->cola_goldbach;
}
/**
 * @brief coseguir nivel de validez del elemento
 * 
 * @param nodo 
 * @return int 
 */
int arreglo_nodo_conseguir_validez(arreglo_nodo_t* nodo) {
  return nodo->validez;
}
