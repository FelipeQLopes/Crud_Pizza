#include "../headers/pizza.h"
#include "../headers/ingrediente.h"
#include "../headers/menu.h"
#include "../headers/pre_processamento.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void menuBreadcrumb(menu* menu){

    strcpy(menu->breadcrumb, "|                                        |");

    char breadcrumb[50] = " > Iniciar";

    switch(menu->operacao[0]){
        case 'C':   
            strcat(breadcrumb, " > Create");
            break;
        case 'R':
            strcat(breadcrumb, " > Read");
            break;
        case 'U':
            strcat(breadcrumb, " > Update");
            break;
        case 'D':
            strcat(breadcrumb, " > Delete");
            break;
        case 'V':
            strcat(breadcrumb, " > Venda");
            break;
    }

    switch(menu->item[0]){
        case 'I':
            strcat(breadcrumb, " > Ingrediente");
            break;
        case 'P':
            strcat(breadcrumb, " > Pizza");
            break;
    }

    strncpy(menu->breadcrumb + 1, breadcrumb, strlen(breadcrumb));
}

void menuCriar(menu menu){
    menuBreadcrumb(&menu);

    limpar_console();
    printf("\n|----------------------------------------|");
    printf("\n|             PIZZARIA QUIJU             |");
    printf("\n|----------------------------------------|");
    printf("\n%s", menu.breadcrumb);
    printf("\n|----------------------------------------|");

}

void menuOperacao(menu menu){

    menu.operacao[0] = '\0';
    menuCriar(menu);
    printf("\n| C - Adicionar Ingredientes ou Pizzas   |");
    printf("\n| R - Ler os Ingredientes ou Pizzas      |");
    printf("\n| U - Editar Ingredientes ou Pizzas      |");
    printf("\n| D - Excluir Ingredientes ou Pizzas     |");
    printf("\n| V - Vender uma Pizza                   |");
    printf("\n| S - Sair                               |");
    printf("\n|----------------------------------------|");
    printf("\n  Opção: ");
}

void menuItem(menu menu){
    menu.item[0] = '\0';
    menuCriar(menu);
    printf("\n| I - Ingredientes                       |");
    printf("\n| P - Pizzas                             |");
    printf("\n| S - Sair                               |");
    printf("\n|----------------------------------------|");
    printf("\n  Opção: ");

}