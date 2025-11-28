#include "../headers/pizza.h"
#include "../headers/ingrediente.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int calcId = 0;

void AddIngredientes(ingrediente **listaIng, int *tamIng)
{
    calcId++;
    int novoTam = *tamIng + 1;
    char espaco = '*';

    ingrediente *novaLista = realloc(*listaIng, sizeof(ingrediente) * novoTam);

    *listaIng = novaLista;
    *tamIng = novoTam;

    (*listaIng)[novoTam - 1].id = calcId;
    printf("\nDigite o nome do ingrediente: ");
    scanf(" %[^\n]", (*listaIng)[novoTam - 1].nome);
    printf("\nDigite o preco do ingrediente: R$ ");
    scanf("%f", &(*listaIng)[novoTam - 1].preco);
    getchar();

    ReadIngredientes(tamIng, *listaIng);

    printf("\nIngrediente adicionado com sucesso!\n");
    while(espaco != ' '){
        printf("\nPressione [ ESPAÇO ] para continuar. \n");
        scanf(" %c", &espaco);
    }

}

int ReadIngredientes(int *tamIng, ingrediente *listaIng)
{
    char resposta;

    printf("\nExibir a lista de ingredientes? [ S ou N ] \n");
    scanf(" %c", &resposta);
    getchar();

    printf("\n");

    resposta = toupper(resposta);

    if (resposta == 'S')
    {
        printf("\n|----------------------------------------|");
        printf("\n|             PIZZARIA QUIJU             |");
        printf("\n|----------------------------------------|");
        printf("\n| %-2s | %-20s | %-10s |", "ID", "Ingrediente", "Preço (R$)");
        printf("\n|----------------------------------------|");
        for (int i = 0; i < *tamIng; i++)
        {
            printf("\n| %-2d | %-20s | R$ %-8.2f|", i, listaIng[i].nome, listaIng[i].preco);
        }
        printf("\n|----------------------------------------|");
    }

    return *tamIng;
}

void UpdateIngredientes(ingrediente *ing)
{
    int escolhaTipo;
    char nomeEdit[50];
    float precoEdit;

    printf("\nDigite o numero do que voce quer editar desse ingrediente:\n");
    printf("\t1 para o NOME \t 2 para o PRECO\n");
    scanf("%d", &escolhaTipo);

    switch (escolhaTipo)
    {
    case 1:
        printf("Digite o novo nome:\n");
        scanf(" %[^\n]", nomeEdit);
        strcpy(ing->nome, nomeEdit);
        printf("\nNome Atualizado com Sucesso!\n");
        break;

    case 2:
        printf("Digite o novo preco:\n");
        scanf("%f", &precoEdit);
        ing->preco = precoEdit;
        printf("\nPreco Atualizado com Sucesso!\n");
        break;

    default:
        printf("Opção inválida.\n");
        break;
    }
}

void DeleteIngredientes(ingrediente **listaIng, int *tamIng)
{
    int idDelete;

    printf("Escolha o ID do ingrediente que voce quer deletar:\n");
    scanf("%d", &idDelete);

    if (idDelete < 0 || idDelete >= *tamIng)
    {
        printf("ID invalido\n");
        return;
    }

    for (int i = idDelete; i < *tamIng - 1; i++)
    {
        (*listaIng)[i] = (*listaIng)[i + 1];
    }

    (*tamIng)--;
    *listaIng = realloc(*listaIng, (*tamIng) * sizeof(ingrediente));

    printf("\nIngrediente deletado com sucesso!\n");
}