/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de crear el arreglo en el cual
 * guardaremos los numeros
 * 
 */
#include "arreglo_de_datos.h"
#include <stdio.h>

typedef struct nodo_arreglo {
  // puntero al siguiente nodo
  nodo_arreglo_t* siguiente;

  // Cola que tiene cada nodo individualmente
  arreglo_t arreglo_goldbach;

  // posicion del valoro en la cola
  int64_t posicion;

  // valor del valoro
  int64_t valor;

  // Indica si el valor es invalido o no 
  int validez;

} nodo_arreglo_t;

void cola_init(arreglo_t* arreglo) {
  assert(arreglo);
  arreglo->primero = NULL;
  arreglo->ultimo = NULL;
}

int cola_insertar(arreglo_t* arreglo, int64_t valor, int valido) {
  assert(arreglo);
  int error = EXIT_SUCCESS;

  
  nodo_arreglo_t* nuevo_nodo = (nodo_arreglo_t*) calloc(1, 
    sizeof(nodo_arreglo_t));  // NOLINT

  
  if (nuevo_nodo) {
    
    nuevo_nodo->valor = valor;
    nuevo_nodo->posicion = 1;
    nuevo_nodo->validez = valido;
    cola_init(&nuevo_nodo->arreglo_goldbach);

    if (arreglo->ultimo == NULL) {
      arreglo->primero = nuevo_nodo;
      arreglo->ultimo = nuevo_nodo;
    } else {
      arreglo->ultimo->siguiente = nuevo_nodo;
      arreglo->ultimo = arreglo->ultimo->siguiente;
    }
  } else {
    error = EXIT_FAILURE;
    fprintf(stderr, "ERROR: no se cuenta con memoria suficiente");
  }
  return error;
}

int cola_posible_insertar(arreglo_t* arreglo, int64_t valor, int valido) {
  assert(arreglo);
  int error = EXIT_SUCCESS;
  error = cola_insertar(arreglo, valor, valido);
  return error;
}

nodo_arreglo_t* cola_buscar(arreglo_t* arreglo, int64_t buscar_valor) {
  assert(arreglo);
  nodo_arreglo_t* actual = arreglo->primero;
  while (actual && actual->valor != buscar_valor) {
    actual = actual->siguiente;
  }
  return actual;
}

void cola_destruir(arreglo_t* arreglo) {
  assert(arreglo);
  nodo_arreglo_t* actual = arreglo->primero;
  nodo_arreglo_t* temp = NULL;

  while (actual) {
    temp = actual->siguiente;
    cola_nodo_destruir(actual);
    actual = temp;
  }
  arreglo->primero = NULL;
  arreglo->ultimo = NULL;
}

void cola_nodo_destruir(nodo_arreglo_t* nodo) {
  nodo->valor = 0;

  cola_destruir(&nodo->arreglo_goldbach);
  free(nodo);
}

int64_t cola_nodo_conseguir_valor(nodo_arreglo_t* nodo) {
  return nodo->valor;
}

int64_t cola_nodo_conseguir_posicion(nodo_arreglo_t* nodo) {
  return nodo->posicion;
}

nodo_arreglo_t* cola_nodo_conseguir_siguiente(nodo_arreglo_t* nodo) {
  return nodo->siguiente;
}

arreglo_t* cola_nodo_conseguir_cola_goldbach(nodo_arreglo_t* nodo) {
  return &nodo->arreglo_goldbach;
}

int cola_nodo_conseguir_validez(nodo_arreglo_t* nodo) {
  return nodo->validez;
}


