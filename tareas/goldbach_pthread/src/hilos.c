#include "hilos.h"

shared_data_t * pthread_init_shared_data(arreglo_t* cola, uint64_t hilos) {
    shared_data_t* shared_data = (shared_data_t *)
        calloc(1, sizeof(shared_data_t)); 
  shared_data->cola = cola;
  shared_data->hilos = hilos;

  return shared_data;
}

int pthread_crear_hilos(shared_data_t* shared_data) {
  int error = EXIT_SUCCESS;
  // Restamos uno porque la ultima posicion no contiene ningun numero
  uint64_t data_size = shared_data->cola->tamano-1;

  if (shared_data->hilos > data_size) {
    // Esto lo hacemo porque no tendria sentido tener hilos de sobra que no harian nada
    shared_data->hilos = data_size;
  }
  // Arreglo con memoria dinamica
  pthread_t * threads = (pthread_t *)  
   calloc(shared_data->hilos, sizeof(pthread_t));  
  // Arreglo con memoria privada para indicar la cantidad de trabajo de cada hilo
  private_data_t * private_data = (private_data_t *)  
   calloc(shared_data->hilos, sizeof(private_data_t));  

  if (threads && private_data) {
    pthread_distribucion(private_data, shared_data);
    for (uint64_t thread_counter = 0;
     thread_counter < shared_data->hilos; ++thread_counter) {
      error = pthread_create(&threads[thread_counter], /*attr*/ NULL,
       goldbach_cola_secundaria, /*arg*/ &private_data[thread_counter]);

      if (error) {
        fprintf(stderr, "ERROR: could not create thread [%lu]\n",
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

void pthread_distribucion(private_data_t * arreglo_privado,
  shared_data_t * shared_data) {
  arreglo_t * cola = shared_data->cola;
  uint64_t hilos = shared_data->hilos;

  //Restamos uno porque la ultima posicion es un numero invalido
  uint64_t cola_size = shared_data->cola->tamano - 1;

  //Tareas minimas de cada hilo
  uint64_t tareas_por_hilo = cola_size / hilos;

  //Hilos que tienen que hacer un poco mas del minimo
  uint64_t extra_threads = cola_size % hilos;

  //Posicion en donde empiezan los hilos extra
  uint64_t posicion_extras = hilos - extra_threads;

  arreglo_nodo_t* temporal = cola->primero;
  arreglo_nodo_t* actual = cola->primero;
  uint64_t contador = 0; // cuenta el numero de tareas
  uint64_t thread_number = 0;

  while (actual) {
    ++contador;
    if (thread_number == posicion_extras) {
      //Aqui agregamos tareas a esos hilos que van a tener que hacer un poco mas de tareas
      ++tareas_por_hilo;
      posicion_extras = 0;
    }

    if (contador == tareas_por_hilo) {
      // Esto lo hacemos para que puedan caber los hilos extra
      arreglo_privado[thread_number].primero = temporal;
      arreglo_privado[thread_number++].ultimo = actual;
      temporal = cola_nodo_conseguir_siguiente(actual);
      contador = 0;
    }
    actual = cola_nodo_conseguir_siguiente(actual);
  }
}