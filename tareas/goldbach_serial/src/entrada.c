#include "entrada.h"
#include "sumas.h"

void entrada_init(entrada_t* entry){
    entrada_t* error = EXIT_SUCCESS;
}

int64_t run(entrada_t* entry){
    arreglo_de_datos_t array;
    arreglo_init(&array);

    entrada_get_file(entry, &array);
    suma_goldbach_total(&array);
    if(entry->error==0)
        entrada_print(&array);
    else
        fprintf(stderr,"There was an error in the program");
    arreglo_destroy(&array);
    return entry->error;
}

