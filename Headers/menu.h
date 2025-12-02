#ifndef MENU_H
#define MENU_H

typedef struct pizzas pizzas;

typedef struct menu{
    char operacao[1]; //C R U D V --> Create, Read, Update, Delete, Venda;
    char item[1]; // I, P --> Ingrediente, Pizza;
    char nomeItem[50];
    char breadcrumb[50];
}menu;

void menuBreadcrumb(menu* menu);
void menuCriar(menu menu);
void menuIniciar(menu menu);
void menuOperacao(menu menu);
void menuItem(menu menu);

#endif