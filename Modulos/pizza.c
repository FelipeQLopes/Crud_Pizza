#include "../Headers/pizza.h"
#include <stdio.h>

void AddIngredientes(FILE *arq, ingrediente ing){

    fprintf(arq, "%d, ", ing.id);
    fputs("%s, ", ing.nome);
    fprintf(arq, "%f,\n", ing.preco);

}

