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

void entrada_get_file(entrada_t* entry, arreglo_de_datos_t* array){
    int64_t current_value = 0;
    int64_t valid = 0;
    while(feof(stdin) == 0){
        if(fscanf(stdin, "%ld", &current_value)==1){
            entrada_validate(&valid);
            entry->error=array_insertion(array,current_value,valid);
            valid = 0;
        }
        else{
            char ignore = '\0';
            while(ignore != EOF && ignore != '\0'){
                ignore = fgetc(stdin);
            }
        }
    }
}

void entrada_validate(int64_t* is_valid){
    if(errno == ERANGE){
        *is_valid = 1;
        clearerr(stdin);
        errno = 0;
    }
}

void entrada_print_sumas(arreglo_nodo_t* current, int64_t value){
    int64_t position = 0;
    int64_t number = 0;
    arreglo_nodo_t* current_sum = get_arreglo_sumas_goldbach(current)->cabeza;
    bool impar = true;
    if(value % 2 == 0){impar = false;}
    int64_t counter = 0;
    while(current_sum){
        position = get_posicion_arreglo(current_sum);
        number = get_value_arreglo(current_sum);
        if(position > 0){
            fprintf(stdout, "%ld + ", number);
            number = 0;
            ++counter;
            if(counter == 3 && impar == true){
                fprintf(stdout,", ");
                counter = 0;
            }
            if(impar==false && counter == 2){
                fprintf(stdout, ", ");
                counter = 0;
            }
        }
        else{
            fprintf(stdout, "%ld", number);
        }
        current_sum = get_siguiente(current_sum);
    }
}

void entrada_print(arreglo_de_datos_t* array){
    arreglo_nodo_t* actual = array->cabeza;
    int64_t value = 0;
    int64_t aux_value = 0;

    while(actual){
        value = get_value_arreglo(actual);
        if(nodo_validate(actual)){
            fprintf(stdout,"%ld: NA\n", value);
        }
        if(value <= 5 && value >= 0){
            fprintf(stdout,"%ld: NA\n", value);
        }
        if(value > 5 || value < -5){
            fprintf(stdout, "%ld: ", value);
            get_sumas_entrada(actual, aux_value);
            if(value < -5){
                aux_value = value + (value * -2);
                entrada_print_sumas(actual, aux_value);
            }
            fprintf(stdout, "\n");
        }
        actual = get_siguiente(actual);
    }
}

void get_sumas_entrada(arreglo_nodo_t* actual, int64_t value){
    bool impar = true;
    if(value % 2 == 0){impar = true;}
    int counter = 0;
    int aux = 0;
    arreglo_nodo_t* current_sum = get_arreglo_sumas_goldbach(actual)->cabeza;
    while(current_sum){
        if(impar){
            ++counter;
        }
        if(counter == 3){
            counter = 0;
            ++aux;
        }
        else{
            if(counter == 2){
                counter = 0;
                ++aux;
            }
        }
        current_sum = get_siguiente(current_sum);
    }
    fprintf(stdout, "%i sums: ", aux);
}



