#include "../headers/pizza.h"
#include "../headers/ingrediente.h"
#include "../headers/menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calcId = 0;

menu menuIng;

void AddIngredientes(ingrediente **listaIng, int *tamIng)
{
    printf(".");
    menuIng.operacao[0] = 'C';
    menuIng.item[0] = 'I';
    calcId++;

    int novoTam = *tamIng + 1;
    char espaco = '*';
    ingrediente *novaLista = realloc(*listaIng, sizeof(ingrediente) * novoTam);
    *listaIng = novaLista;
    *tamIng = novoTam;

    (*listaIng)[novoTam - 1].id = calcId;
    menuCriar(menuIng);
    printf("\n| Nome: ");
    scanf(" %[^\n]", (*listaIng)[novoTam - 1].nome);
    printf("| Preço: R$ ");
    scanf("%f", &(*listaIng)[novoTam - 1].preco);
    printf("|----------------------------------------|\n");
    printf("|  Ingrediente adicionado com sucesso!   |\n");
    printf("|                                        |\n");
    printf("|  Pressione [ ENTER ] para continuar.   |\n");
    printf("|----------------------------------------|\n ");
    getchar();
    getchar();


}

int ReadIngredientes(int *tamIng, ingrediente *listaIng, menu menu2)
{
    menu2.operacao[0] = 'R';
    menu2.item[0] = 'I';
    char espaco;
    int i;
    
    menuCriar(menu2);
    printf("\n|    |                      |            |");
    printf("\n| %-2s | %-20s | %-10s |", "ID", "    Ingrediente", "Preço (R$)");
    printf("\n|    |                      |            |");
    printf("\n|----------------------------------------|");
    for (i = 0; i < *tamIng; i++)
    {
        printf("\n| %-2d | %-20s | R$ %-8.2f|", i, (listaIng)[i].nome, (listaIng)[i].preco);
    }
    if(i==0){
        printf("\n|     Nenhum ingrediente encontrado!     |");
    }
    printf("\n|----------------------------------------|\n");
    printf("|  Pressione [ ENTER ] para continuar.   |\n");
    printf("|----------------------------------------|\n ");
    getchar();
    
    return *tamIng;
}

void UpdateIngredientes(ingrediente *ing)
{
    menuIng.operacao[0] = 'U';
    menuIng.item[0] = 'I';
    char nomeEdit[50];
    float precoEdit;

    menuCriar(menuIng);
    printf("\n|  Insira -1 para manter o valor antigo  |");
    printf("\n|----------------------------------------|");
    printf("\n| Nome: ");
    scanf(" %[^\n]", nomeEdit);
    printf("| Preço: R$ ");
    scanf("%f", &precoEdit);
    getchar();

    if(strcmp(nomeEdit, "-1")!=0){
        strcpy(ing->nome, nomeEdit);
    }
    if(precoEdit != -1){
        ing->preco = precoEdit;
    }

    printf("|----------------------------------------|\n");
    printf("|  Ingrediente atualizado com sucesso!   |\n");
    printf("|                                        |\n");
    printf("|  Pressione [ ENTER ] para continuar.   |\n");
    printf("|----------------------------------------|\n ");
    getchar();
}

void DeleteIngredientes(ingrediente **listaIng, int *tamIng)
{
    menuIng.operacao[0] = 'D';
    menuIng.item[0] = 'I';
    int idDelete;

    menuCriar(menuIng);
    printf("\n| ID do ingrediente para deletar:        |\n| ");
    scanf("%d", &idDelete);
    getchar();

    if (idDelete < 0 || idDelete >= *tamIng)
    {
        printf("| ID invalido                            |\n");
        return;
    }

    for (int i = idDelete; i < *tamIng - 1; i++)
    {
        (*listaIng)[i] = (*listaIng)[i + 1];
    }

    (*tamIng)--;
    *listaIng = realloc(*listaIng, (*tamIng) * sizeof(ingrediente));

    printf("|----------------------------------------|\n");
    printf("|   Ingrediente excluído com sucesso!    |\n");
    printf("|                                        |\n");
    printf("|  Pressione [ ENTER ] para continuar.   |\n");
    printf("|----------------------------------------|\n ");
    getchar();
}