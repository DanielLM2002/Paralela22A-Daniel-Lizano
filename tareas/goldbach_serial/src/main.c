#include "entrada.h"
int main(void){
    entrada_t entry;
    entrada_init(&entry);
    run(&entry);
    return entry.error;
}
