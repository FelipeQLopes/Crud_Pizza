#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "Headers/ingrediente.h"
#include "Headers/pizza.h"

void escolher(char escolha1, ingrediente** listaIng, pizzas** listaPizza, int* tamIng, int* tamPiz);

int main() {
    char escolha;
    ingrediente *listaIng = malloc(sizeof(ingrediente));
    pizzas *listaPizza = malloc(sizeof(pizzas));
    int tamIng = 1;
    int tamPiz = 1;

    printf("\nBem-Vindo ao programa da Pizzaria QUIJU\n");

    printf("\nPara utilizar as funcoes do programa digite C caso queira adicionar tanto pizzas quanto ingredientes, R caso queira ler ingredientes ou pizzas,\nU caso queira editar um dado e D caso queira deletar um ingrediente ou pizza:\n");

    scanf(" %c", &escolha);
    escolha = toupper(escolha);

    while (escolha == 'C' || escolha == 'R' || escolha == 'U' || escolha == 'D') {
        escolher(escolha, &listaIng, &listaPizza, &tamIng, &tamPiz);

        printf("\nNovamente caso queira utilizar as funcoes digite C para adicionar, R para ler, U para editar e D para deletar\n");
        scanf(" %c", &escolha);
        escolha = toupper(escolha);
    }

    return 0;
}

void escolher(char escolha1, ingrediente** listaIng, pizzas** listaPizza, int* tamIng, int* tamPiz){

    char escolha2;
    int idUpdate, idDelete;

    printf("\nVoce quer fazer isso para um ingrediente ou para uma pizza? (I), (P)\n");
    scanf(" %c", &escolha2);
    escolha2 = toupper(escolha2);
    getchar();  
    printf("\n");

    switch (escolha1) {
        case 'C': 
            if (escolha2 == 'I') {
                AddIngredientes(listaIng, tamIng); 
            } else if (escolha2 == 'P') {
                AddPizza(listaPizza, tamPiz, *listaIng, tamIng); 
            }
            break;

        case 'R': 
            if (escolha2 == 'I') {
                ReadIngredientes(tamIng, *listaIng); 
            } else if (escolha2 == 'P') {
                ReadPizza(tamPiz, *listaPizza); 
            }
            break;

        case 'U': 
            if (escolha2 == 'I') {
                printf("Escolha o id do ingrediente que voce quer editar:\n");
                scanf("%d", &idUpdate);
                UpdateIngredientes(&(*listaIng)[idUpdate]);
            } else if (escolha2 == 'P') {
                printf("Escolha o id da pizza que voce quer editar:\n");
                scanf("%d", &idUpdate);
                UpdatePizzas(&(*listaPizza)[idUpdate]);
            }
            break;

        case 'D': 
            if (escolha2 == 'I') {
                printf("Escolha o id do ingrediente que voce quer deletar:\n");
                scanf("%d", &idDelete);
                DeleteIngredientes(&(*listaIng)[idUpdate]);
            } else if (escolha2 == 'P') {
                printf("Escolha o id da pizza que voce quer deletar:\n");
                scanf("%d", &idDelete);
                DeletePizzas(&(*listaPizza)[idUpdate]);
            }

            break;

        default:
            printf("Opção inválida.\n");
            break;
    }
}
