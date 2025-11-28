#ifndef MENU_H
#define MENU_H

typedef struct menu{
    char operacao; //C R U D V --> Create, Read, Update, Delete, Venda;
    char item; // I, P --> Ingrediente, Pizza;
    char breadcrumb[40];
}menu;

void definirBreadcrumb();

#endif