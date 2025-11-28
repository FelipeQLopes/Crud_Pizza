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

    ingrediente *novaLista = realloc(*listaIng, sizeof(ingrediente) * novoTam);

    *listaIng = novaLista;
    *tamIng = novoTam;

    (*listaIng)[novoTam - 1].id = calcId;
    printf("Digite o nome do ingrediente: ");
    scanf(" %[^\n]", (*listaIng)[novoTam - 1].nome);
    printf("Digite o preco do ingrediente: ");
    scanf("%f", &(*listaIng)[novoTam - 1].preco);
    getchar();

    ReadIngredientes(tamIng, *listaIng);

    printf("Ingrediente adicionado com sucesso!\n");
}

int ReadIngredientes(int *tamIng, ingrediente *listaIng)
{
    char resposta;

    printf("\nVoce quer ver a lista de ingredientes? (S/N)\n");
    scanf(" %c", &resposta);
    getchar();

    printf("\n");

    resposta = toupper(resposta);

    if (resposta == 'S')
    {
        for (int i = 0; i < *tamIng; i++)
        {
            printf("ID: %-3d, Ingrediente: %-25s, Preco: R$ %-5.2f\n", i, listaIng[i].nome, listaIng[i].preco);
        }
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