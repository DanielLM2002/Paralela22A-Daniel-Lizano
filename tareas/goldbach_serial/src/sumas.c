#include <math.h>
#include <stdlib.h>
#include <stdint.h>
#include "sumas.h"

int suma_goldbach_total(arreglo_de_datos_t* array) {
    int64_t value = 0;
    arreglo_nodo_t* current_position = array ->cabeza;
    arreglo_de_datos_t* array_goldbach_actual = NULL;
    int error = EXIT_SUCCESS;

    while(current_position && error ==0) {
        array_goldbach_actual = get_arreglo_sumas_goldbach(current_position);
        value = get_value_arreglo(current_position);
        if (value < 0) {
            value = value + (value * -2);
        }

        else if (value > 5 && 
                get_arreglo_sumas_goldbach(current_position) == 0) {
            error = suma_goldbach_numero(array_goldbach_actual, value);
        }
        current_position = get_siguiente(current_position);
    }
    if(error) {
        fprintf(stderr,"The system lacks memory");
    }
    return error;
}

bool suma_prima(int64_t number) {
    bool result = true;
    if (number >= 2) {
        result = true;
        int64_t max = number - 1;
        for (int i = 2; i <= max; ++i) {
            if (number % i == 0) {
                result = false;
            }
        }
    }
    return result;
}

int suma_par(arreglo_de_datos_t* array_sums, int64_t number) {
    int error = EXIT_SUCCESS;
    for(int64_t i = 2; i < number; ++i) {
        if(suma_prima(i) == true) {
            for(int64_t j=0; j < number; ++j) {
                if(i + j == number && suma_prima(j) == true) {
                    error = array_insertion(array_sums, i, 0);
                    error = array_insertion(array_sums, j, 0);
                }
            }
        }
    }
    return error;
}

int suma_impar(arreglo_de_datos_t* array_sums, int64_t number) {
    int error = EXIT_FAILURE;
    for (int64_t iterator = 2; iterator < number; ++iterator) {
        if (suma_prima(iterator) == true) {
            for (int64_t j = 2; j< number; ++j) {
                if (suma_prima(j)==true) {
                    for(int64_t k = 2; k < number; ++k) {
                        if(iterator + j + k == number && suma_prima(k)) {
                            if(iterator <= k && iterator <= j && j <= k) {
                            error = array_insertion(array_sums, iterator, 0);
                            error = array_insertion(array_sums, j, 0);
                            error = array_insertion(array_sums, k, 0);
                            }
                        }
                    }
                }
            }
        }
    }
    return error;
}

int suma_goldbach_numero(arreglo_de_datos_t* array_sums, int64_t number) {
    if (number % 2 == 0) {
        return suma_par(array_sums, number);
    }
    else {
        return suma_impar(array_sums, number);
    }
}
