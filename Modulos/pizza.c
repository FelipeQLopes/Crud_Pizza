#include "../Headers/pizza.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int pizzaId = 0;

void AddPizza(pizzas pizza, ingrediente *listadeIng){

    int escolhaIng, i = 0, cont = 0;
    char resposta;

    calcId++;
    pizza.id = calcId;

    ingrediente *pizzaIng = (ingrediente *)malloc(sizeof(ingrediente) * 10);

    printf("Digite o nome da pizza: ");
    scanf("%[^\n]", pizza.nome);
    printf("Digite o tamanho da pizza ( P, M, G): ");
    scanf("%c", &pizza.tamanho);
    printf("Digite o preco da pizza: ");
    scanf("%f", &pizza.preco);

    printf("Voce quer ver a lista de ingredientes? (S/N)");
    scanf("%c", &resposta);

    resposta = toupper(resposta);

    if(resposta = 'S'){

        for( i = 1 ; i <= sizeof(listadeIng)/sizeof(ingrediente); i++){

            printf("ID: %d, Ingrediente: %s \n", listadeIng[i].id, listadeIng[i].nome);

        }
    }

    printf("Agora escolha ate 10 ingredientes para sua pizza. \n");
    printf("(Escolha digitando o ID dos ingredientes separado por Espacos ou ENTER, \n para finalizar a operacao digite um id que nao exista)\n");

    scanf("%d", &escolhaIng);

    while(escolhaIng > 0 && escolhaIng < i && cont < 10){

        scanf("%d", &pizzaIng[cont].id);

        cont++;

        scanf("%d", &escolhaIng);

    }

    printf("Pizza Adicionada\n");
    
}


