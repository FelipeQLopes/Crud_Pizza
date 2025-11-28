#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "headers/pre_processamento.h"
#include "headers/ingrediente.h"
#include "headers/pizza.h"

void escolher(char escolha1, ingrediente **listaIng, pizzas **listaPizza, int *tamIng, int *tamPiz);
void menu_inicio();
void menu_escolher(char escolha);

int main()
{

    FILE *arquivoIng;
    FILE *arquivoPiz;

    arquivoIng = fopen("Ing.txt", "r");
    arquivoPiz = fopen("Piz.txt", "r");

    char escolha = '*';

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

    while (escolha != 'S')
    {
        menu_inicio();
        scanf(" %c", &escolha);
        escolha = toupper(escolha);
        escolher(escolha, &listaIng, &listaPizza, &tamIng, &tamPiz);
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

    menu_escolher(escolha1);
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

void menu_inicio()
{
    limpar_console();
    printf("\n|----------------------------------------|");
    printf("\n|             PIZZARIA QUIJU             |");
    printf("\n|----------------------------------------|");
    printf("\n| > Início                               |");
    printf("\n| C - Adicionar Ingredientes ou Pizzas   |");
    printf("\n| R - Ler os Ingredientes ou Pizzas      |");
    printf("\n| U - Editar Ingredientes ou Pizzas      |");
    printf("\n| D - Excluir Ingredientes ou Pizzas     |");
    printf("\n| V - Vender uma Pizza                   |");
    printf("\n| S - Sair                               |");
    printf("\n|----------------------------------------|\n");
    printf("\n  Opção: ");
}

void menu_escolher(char escolha)

{
    char breadcrumb[40] = "";

    switch (escolha)
    {
        case 'C':
            strcpy(breadcrumb, "Create                      ");
            break;
        case 'R':
            strcpy(breadcrumb, "Read                        ");
            break;
        case 'U':
            strcpy(breadcrumb, "Update                      ");
            break;
        case 'D':
            strcpy(breadcrumb, "Delete                      ");
            break;
        case 'V':
            strcpy(breadcrumb, "Venda                       ");
            break;
    }
    limpar_console();
    printf("\n|----------------------------------------|");
    printf("\n|             PIZZARIA QUIJU             |");
    printf("\n|----------------------------------------|");
    printf("\n| > Início > %s|", breadcrumb);
    printf("\n| I - Ingredientes                       |");
    printf("\n| P - Pizzas                             |");
    printf("\n| S - Sair                               |");
    printf("\n|----------------------------------------|\n");
    printf("\n  Opção: ");
}