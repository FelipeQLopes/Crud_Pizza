#include "../Headers/ingrediente.h"
#include <stdio.h>

void AddIngredientes(ingrediente ing, FILE *arq){

    fprintf(arq, "%d, ", &ing.id);
    fputs("%s, ", ing.nome, arq);
    fprintf(arq, "%f,\n", &ing.preco);

}

