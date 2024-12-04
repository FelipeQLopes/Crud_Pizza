#include "../Headers/ingrediente.h"
#include <stdio.h>

int calcId = 0;

void AddIngredientes(ingrediente ing){

    calcId++;
    ing.id = calcId;

    printf("Digite o nome do ingrediente: ");
    fgets(ing.nome, 30, stdin);
    printf("Digite o preco do ingrediente: ");
    scanf("%f", &ing.preco);


}

