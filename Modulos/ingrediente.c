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

int ReadIngredientes(int *tamIng, ingrediente *listaIng)
{
    menuIng.operacao[0] = 'R';
    menuIng.item[0] = 'I';
    char resposta;
    char espaco;
    int i;

    menuCriar(menuIng);

    printf("\n");

    resposta = toupper(resposta);

    menuCriar(menuIng);
    printf("\n|    |                      |            |");
    printf("\n| %-2s | %-20s | %-10s |", "ID", "    Ingrediente", "Preço (R$)");
    printf("\n|    |                      |            |");
    printf("\n|----------------------------------------|");
    for (i = 0; i < *tamIng; i++)
    {
        printf("\n| %-2d | %-20s | R$ %-8.2f|", i, listaIng[i].nome, listaIng[i].preco);
    }
    if(i==0){
        printf("\n|     Nenhum ingrediente encontrado!     |\n");
    }
    printf("|----------------------------------------|\n");
    printf("|  Pressione [ ENTER ] para continuar.   |\n");
    printf("|----------------------------------------|\n ");
    getchar();

    return *tamIng;
}

void UpdateIngredientes(ingrediente *ing)
{
    menuIng.operacao[0] = 'U';
    menuIng.item[0] = 'I';
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
    menuIng.operacao[0] = 'D';
    menuIng.item[0] = 'I';
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