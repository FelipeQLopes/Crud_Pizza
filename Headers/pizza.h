#ifndef PIZZA_H
#define PIZZA_H

#include "ingrediente.h"

typedef struct pizzas {
    int id;
    char nome[50];
    char tamanho;
    float preco;
    ingrediente* ing;
    int num_ingredientes;
}pizzas;


void AddPizza(pizzas** listaPizza, int* tamPiz, ingrediente* listaIng, int* tamIng);
int ReadPizza(int* tamPiz, pizzas* listaPizza);
void UpdatePizzas(pizzas* piz);
void DeletePizzas(pizzas* piz);

#endif // PIZZA_H
