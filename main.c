#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "headers/ingrediente.h"
#include "headers/pizza.h"

void escolher(char escolha1, ingrediente **listaIng, pizzas **listaPizza, int *tamIng, int *tamPiz);

int main()
{

    FILE *arquivoIng;
    FILE *arquivoPiz;

    arquivoIng = fopen("Ing.txt", "r");
    arquivoPiz = fopen("Piz.txt", "r");

    char escolha;
    ingrediente *listaIng = malloc(sizeof(ingrediente));
    ingrediente *readIng = malloc(sizeof(ingrediente));
    pizzas *listaPizza = malloc(sizeof(pizzas));
    pizzas *readPiz = malloc(sizeof(pizzas));
    int tamIng = 0;
    int tamPiz = 0;

    if (arquivoIng != NULL)
    {
        while (fread(readIng, sizeof(ingrediente), 1, arquivoIng) != 0)
        {
            listaIng[tamIng] = *readIng;
            tamIng++;
            listaIng = realloc(listaIng, sizeof(ingrediente) * (tamIng + 1));
        }
        printf("\nDados de ingredientes importados com sucesso!\n");
    }
    if (arquivoIng != NULL)
    {

        while (fread(readPiz, sizeof(pizzas), 1, arquivoPiz) != 0)
        {
            listaPizza[tamPiz] = *readPiz;
            tamPiz++;
            listaPizza = realloc(listaPizza, sizeof(pizzas) * (tamPiz + 1));
        }

        printf("\nDados de pizzas importados com sucesso!\n");
    }
    printf("\nBem-Vindo ao programa da Pizzaria QUIJU\n");

    printf("\nPara utilizar as funcoes do programa digite C caso queira adicionar tanto pizzas quanto ingredientes, R caso queira ler ingredientes ou pizzas,\nU caso queira editar um dado, D caso queira deletar um ingrediente ou pizza e V caso queira vender uma pizza:\n");

    scanf(" %c", &escolha);
    escolha = toupper(escolha);

    while (escolha == 'C' || escolha == 'R' || escolha == 'U' || escolha == 'D' || escolha == 'V')
    {
        escolher(escolha, &listaIng, &listaPizza, &tamIng, &tamPiz);

        printf("\nNovamente caso queira utilizar as funcoes digite C para adicionar, R para ler, U para editar, D para deletar e V para vender\n");
        scanf(" %c", &escolha);
        escolha = toupper(escolha);
    }

    arquivoIng = fopen("Ing.txt", "w");
    fwrite(listaIng, sizeof(ingrediente), tamIng, arquivoIng);
    printf("\nDados de ingredientes exportados com sucesso!\n");

    arquivoPiz = fopen("Piz.txt", "w");
    fwrite(listaPizza, sizeof(pizzas), tamPiz, arquivoPiz);
    printf("\nDados de pizzas exportados com sucesso!\n\n");

    return 0;
}

void escolher(char escolha1, ingrediente **listaIng, pizzas **listaPizza, int *tamIng, int *tamPiz)
{

    char escolha2;
    int idUpdate;

    printf("\nVoce quer fazer isso para um ingrediente ou para uma pizza? (I), (P)\n");
    scanf(" %c", &escolha2);
    escolha2 = toupper(escolha2);
    getchar();
    printf("\n");

    switch (escolha1)
    {
    case 'C':
        if (escolha2 == 'I')
        {
            AddIngredientes(listaIng, tamIng);
        }
        else if (escolha2 == 'P')
        {
            AddPizza(listaPizza, tamPiz, *listaIng, tamIng);
        }
        break;

    case 'R':
        if (escolha2 == 'I')
        {
            ReadIngredientes(tamIng, *listaIng);
        }
        else if (escolha2 == 'P')
        {
            ReadPizza(tamPiz, *listaPizza);
        }
        break;

    case 'U':
        if (escolha2 == 'I')
        {
            printf("Escolha o id do ingrediente que voce quer editar:\n");
            scanf("%d", &idUpdate);
            UpdateIngredientes(&(*listaIng)[idUpdate]);
        }
        else if (escolha2 == 'P')
        {
            printf("Escolha o id da pizza que voce quer editar:\n");
            scanf("%d", &idUpdate);
            UpdatePizzas(&(*listaPizza)[idUpdate]);
        }
        break;

    case 'D':
        if (escolha2 == 'I')
        {
            DeleteIngredientes(listaIng, tamIng);
        }
        else if (escolha2 == 'P')
        {
            DeletePizzas(listaPizza, tamPiz);
        }

        break;

    case 'V':
        if (escolha2 == 'I')
        {
            printf("Nao da para vender um ingrediente\n");
            return;
        }
        if (escolha2 == 'P')
        {
            venderPizza(listaPizza, tamPiz, *listaIng, tamIng);
        }

        break;

    default:
        printf("Opção inválida.\n");
        break;
    }
}