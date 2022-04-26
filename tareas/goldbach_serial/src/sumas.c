#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include "sumas.h"

int suma_goldbach_total(arreglo_de_datos_t* array){
    int64_t value = 0;
    arreglo_nodo_t* current_position = array ->cabeza;
    arreglo_de_datos_t* array_goldbach_actual = NULL;
    int error = EXIT_SUCCESS;

    while(current_position && error ==0){
        array_goldbach_actual = get_arreglo_sumas_goldbach(current_position);
        value = get_value_arreglo(current_position);
        if(value < 0){
            value = value + (value* -2);
        }

        else if(value > 5 && get_arreglo_sumas_goldbach(current_position) == 0){
            error = suma_goldbach_numero(value, array_goldbach_actual);
        }
        current_position = get_siguiente(current_position);
    }
    if(error){
        fprintf(stderr,"The system lacks memory");
    }
    return error;
}

bool suma_prima(int64_t number){
    bool result;
    if(number >= 2) {result = true;}
    int64_t max = number - 1;
    for(int64_t iterator = 2; iterator <= max; ++iterator){
        if(number % iterator == 0) {result = false;}
    }
}

int suma_par(arreglo_de_datos_t* array_sums, int64_t number){
    int error = EXIT_SUCCESS;
    for(int64_t iterator = 2; iterator < number; ++iterator){
        if()
    }
}

