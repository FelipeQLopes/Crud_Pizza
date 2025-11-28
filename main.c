#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "headers/pre_processamento.h"
#include "headers/ingrediente.h"
#include "headers/pizza.h"
#include "headers/menu.h"

void escolher(char escolha1, ingrediente **listaIng, pizzas **listaPizza, int *tamIng, int *tamPiz, menu menuMain);

int main()
{

    FILE *arquivoIng;
    FILE *arquivoPiz;
    menu menuMain;

    arquivoIng = fopen("Ing.txt", "r");
    arquivoPiz = fopen("Piz.txt", "r");

    char escolha = '*';

    ingrediente *listaIng = NULL;
    ingrediente *readIng = malloc(sizeof(ingrediente));
    pizzas *listaPizza = NULL;
    pizzas *readPiz = malloc(sizeof(pizzas));
    int tamIng = 0;
    int tamPiz = 0;

    if (arquivoIng != NULL)
    {
        while (fread(readIng, sizeof(ingrediente), 1, arquivoIng) == 1)
        {
            listaIng = realloc(listaIng, sizeof(ingrediente) * (tamIng + 1));
            if (listaIng == NULL) {
                printf("Erro de memória ao importar ingredientes!\n");
                exit(1);
            }
            listaIng[tamIng] = *readIng;
            tamIng++;
        }
        fclose(arquivoIng);
        printf("\nDados de ingredientes importados com sucesso!\n");
    }
    // Se não importou nada, inicializa com espaço mínimo
    if (listaIng == NULL) {
        listaIng = malloc(sizeof(ingrediente));
        if (listaIng == NULL) {
            printf("Erro de memória ao inicializar ingredientes!\n");
            exit(1);
        }
        tamIng = 0;
    }
    if (arquivoPiz != NULL)
    {
        while (fread(readPiz, sizeof(pizzas), 1, arquivoPiz) == 1)
        {
            listaPizza = realloc(listaPizza, sizeof(pizzas) * (tamPiz + 1));
            if (listaPizza == NULL) {
                printf("Erro de memória ao importar pizzas!\n");
                exit(1);
            }
            listaPizza[tamPiz] = *readPiz;
            tamPiz++;
        }
        fclose(arquivoPiz);
        printf("\nDados de pizzas importados com sucesso!\n");
    }
    // Se não importou nada, inicializa com espaço mínimo
    if (listaPizza == NULL) {
        listaPizza = malloc(sizeof(pizzas));
        if (listaPizza == NULL) {
            printf("Erro de memória ao inicializar pizzas!\n");
            exit(1);
        }
        tamPiz = 0;
    }
    free(readIng);
    free(readPiz);

    while (escolha != 'S')
    {
        menuOperacao(menuMain);
        scanf(" %c", &escolha);
        escolha = toupper(escolha);
        if (escolha == 'S') break;
        menuMain.operacao[0] = escolha;
        escolher(escolha, &listaIng, &listaPizza, &tamIng, &tamPiz, menuMain);
    }

    arquivoIng = fopen("Ing.txt", "w");
    if (arquivoIng != NULL && listaIng != NULL && tamIng > 0) {
        fwrite(listaIng, sizeof(ingrediente), tamIng, arquivoIng);
        fclose(arquivoIng);
        printf("\nDados de ingredientes exportados com sucesso!\n");
    }

    arquivoPiz = fopen("Piz.txt", "w");
    if (arquivoPiz != NULL && listaPizza != NULL && tamPiz > 0) {
        fwrite(listaPizza, sizeof(pizzas), tamPiz, arquivoPiz);
        fclose(arquivoPiz);
        printf("\nDados de pizzas exportados com sucesso!\n\n");
    }

    free(listaIng);
    free(listaPizza);

    return 0;
}

void escolher(char escolha1, ingrediente **listaIng, pizzas **listaPizza, int *tamIng, int *tamPiz, menu menuMain)
{
    char escolha2;
    int idUpdate;

    menuItem(menuMain);
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