/**
 * Copyright [2022] Daniel Lizano UCR
 * Clase encargada de implementar los metodos de hilos
 * 
 */
#include "hilos.h"
/**
 * @brief metodo para iniciar los hilos de shared data
 * 
 * @param cola 
 * @param hilos 
 * @return shared_data_t* 
 */
shared_data_t * pthread_init_shdata(arreglo_t* cola, uint64_t hilos) {
    shared_data_t* shared_data = (shared_data_t *)
        calloc(1, sizeof(shared_data_t));
  shared_data->cola = cola;
  shared_data->hilos = hilos;

  return shared_data;
}
/**
 * @brief metodo paracrear los hilos en el programa
 * tambien se encarga de revisar cuantos hilos hay y si son
 * necesarios para la tarea a realizar
 * 
 * @param shared_data 
 * @return int 
 */
int pthread_crear_hilos(shared_data_t* shared_data) {
  int error = EXIT_SUCCESS;
  uint64_t data_size = shared_data->cola->tamanio-1;

  if (shared_data->hilos > data_size) {
    shared_data->hilos = data_size;
  }
  pthread_t* threads = (pthread_t *) calloc(shared_data->hilos,
    sizeof(pthread_t));
  private_data_t* private_data = (private_data_t *) calloc(shared_data->hilos,
    sizeof(private_data_t));
  if (threads && private_data) {
    pthread_repartir(private_data, shared_data);
    for (uint64_t thread_counter = 0;
     thread_counter < shared_data->hilos; ++thread_counter) {
      error = pthread_create(&threads[thread_counter], /*attr*/ NULL,
       goldbach_suma_aux, /*arg*/ &private_data[thread_counter]);
      if (error) {
        fprintf(stderr, "ERROR: No se puede crear el hilo [%lu]\n",
          thread_counter);
        break;
      }
    }
  }

  for (uint64_t thread_counter = 0;
  thread_counter < shared_data->hilos; ++thread_counter) {
    pthread_join(threads[thread_counter], /*value_ptr*/ NULL);
  }
  free(private_data);
  free(threads);
  return error;
}

void pthread_repartir(private_data_t* arreglo_privado,
  shared_data_t * shared_data) {
  arreglo_t* cola = shared_data->cola;
  uint64_t hilos = shared_data->hilos;
  uint64_t cola_size = shared_data->cola->tamanio - 1;
  // Tareas minimas de cada hilo
  uint64_t tareas_hilo = cola_size / hilos;
  uint64_t hilos_aux = cola_size % hilos;
  uint64_t posicion_extras = hilos - hilos_aux;

  arreglo_nodo_t* temporal = cola->primero;
  arreglo_nodo_t* actual = cola->primero;
  uint64_t contador_tareas = 0;
  uint64_t thread_number = 0;

  while (actual) {
    ++contador_tareas;
    if (thread_number == posicion_extras) {
      ++tareas_hilo;
      posicion_extras = 0;
    }

    if (contador_tareas == tareas_hilo) {
      arreglo_privado[thread_number].primero = temporal;
      arreglo_privado[thread_number++].ultimo = actual;
      temporal = arreglo_nodo_conseguir_siguiente(actual);
      contador_tareas = 0;
    }
    actual = arreglo_nodo_conseguir_siguiente(actual);
  }
}
