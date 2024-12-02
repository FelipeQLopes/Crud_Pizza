#include "../Headers/ingrediente.h"
#include <stdio.h>

void AddIngredientes(ingrediente ing, FILE *arq){

    fprintf(arq, "%d\n", &ing.id);
    

}