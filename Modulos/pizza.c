#include "../headers/pizza.h"
#include "../headers/ingrediente.h"
#include "../headers/menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int pizzaId = 0;
menu menuPiz;

void AddPizza(pizzas **listaPizza, int *tamPiz, ingrediente *listaIng, int *tamIng)
{   
    menuPiz.operacao[0] = 'C';
    menuPiz.item[0] = 'P';
    pizzaId++;
    *tamPiz += 1;

    *listaPizza = realloc(*listaPizza, sizeof(pizzas) * (*tamPiz));

    pizzas *novaPizza = &(*listaPizza)[*tamPiz - 1];
    novaPizza->id = pizzaId;

    printf("Digite o nome da pizza: ");
    scanf(" %[^\n]", novaPizza->nome);
    getchar();
    printf("Digite o tamanho da pizza (P, M, G): ");
    scanf("%c", &novaPizza->tamanho);
    novaPizza->tamanho = toupper(novaPizza->tamanho);
    getchar();
    printf("Digite o preco da pizza: ");
    scanf("%f", &novaPizza->preco);
    getchar();

    int qtdIng = ReadIngredientes(tamIng, listaIng);

    novaPizza->ing = malloc(sizeof(ingrediente) * 10);
    novaPizza->num_ingredientes = 0;

    printf("\nAgora escolha até 10 ingredientes para sua pizza.\n");
    printf("(Escolha digitando o ID dos ingredientes, ou um ID inválido para finalizar):\n");

    int escolhaIng;
    while (novaPizza->num_ingredientes < 10)
    {
        printf("Escolha o ID do ingrediente: ");
        scanf("%d", &escolhaIng);

        if (escolhaIng < 0 || escolhaIng >= qtdIng)
        {
            break;
        }

        novaPizza->ing[novaPizza->num_ingredientes] = listaIng[escolhaIng];
        novaPizza->num_ingredientes++;
    }

    printf("Pizza adicionada com sucesso!\n");
}

int ReadPizza(int *tamPiz, pizzas *listaPizza)
{
    menuPiz.operacao[0] = 'R';
    menuPiz.item[0] = 'P';
    char resposta;
    int respostaId;

    printf("\nVoce quer ver a lista de pizzas? (S/N)\n");
    scanf(" %c", &resposta);
    getchar();

    resposta = toupper(resposta);

    if (resposta == 'S')
    {
        for (int i = 0; i < *tamPiz; i++)
        {
            printf("ID: %-3d, Pizza: %-25s, Tamanho: %-5.c Preco: R$ %-5.2f\n", i, listaPizza[i].nome, listaPizza[i].tamanho, listaPizza[i].preco);
        }
    }

    printf("\nVoce quer ver os ingredientes de alguma pizza? (S/N)\n");
    scanf(" %c", &resposta);
    getchar();

    resposta = toupper(resposta);

    if (resposta == 'S')
    {
        printf("\nDigite o ID de qual pizza voce deseja ver os ingredientes\n");
        scanf("%d", &respostaId);
        for (int k = 0; k < listaPizza[respostaId].num_ingredientes; k++)
        {

            printf("Ingrediente %2d: %-25s\n", k + 1, listaPizza[respostaId].ing[k].nome);
        }
    }

    return *tamPiz;
}

void UpdatePizzas(pizzas *piz)
{
    menuPiz.operacao[0] = 'U';
    menuPiz.item[0] = 'P';
    int escolhaTipo, qtdIngEdit;
    char nomeEdit[50], tamanhoEdit;
    float precoEdit;

    printf("\nDigite o numero do que voce quer editar desse ingrediente:\n");
    printf("\t1 para o NOME \t 2 para o TAMANHO \t 3 para o PRECO\n");
    scanf("%d", &escolhaTipo);

    switch (escolhaTipo)
    {

    case 1:
        printf("Digite o novo nome:\n");
        scanf(" %[^\n]", nomeEdit);
        strcpy(piz->nome, nomeEdit);
        printf("\nNome Atualizado com Sucesso!\n");

        break;

    case 2:
        printf("Digite o novo tamanho:");
        scanf(" %c", &tamanhoEdit);
        piz->tamanho = tamanhoEdit;
        printf("\nTamanho Atualizado com Sucesso!\n");

        break;

    case 3:
        printf("Digite o novo preco:");
        scanf("%f", &precoEdit);
        piz->preco = precoEdit;
        printf("\nPreco Atualizado com Sucesso!\n");

        break;
    }
}

void DeletePizzas(pizzas **listaPizza, int *tamPiz)
{
    menuPiz.operacao[0] = 'D';
    menuPiz.item[0] = 'P';
    int idDelete;

    printf("Escolha o ID da Pizza que voce quer deletar:\n");
    scanf("%d", &idDelete);

    if (idDelete < 0 || idDelete >= *tamPiz)
    {
        printf("ID invalido\n");
        return;
    }

    for (int i = idDelete; i < *tamPiz - 1; i++)
    {
        (*listaPizza)[i] = (*listaPizza)[i + 1];
    }

    (*tamPiz)--;
    *listaPizza = realloc(*listaPizza, (*tamPiz) * sizeof(pizzas));

    printf("\nPizza deletada com Sucesso!\n");
}

void venderPizza(pizzas **listaPizza, int *tamPiz, ingrediente *listaIng, int *tamIng)
{
    menuPiz.operacao[0] = 'V';
    menuPiz.item[0] = 'P';
    char resposta;
    int idVender, escolhaIng;
    float soma = 0;

    printf("\nVoce esta vendendo uma pizza:\n");

    ReadPizza(tamPiz, *listaPizza);

    printf("Escolha o ID da Pizza que voce quer vender:\n");
    scanf("%d", &idVender);

    if (idVender < 0 || idVender >= *tamPiz)
    {
        printf("\nID invalido\n");
        return;
    }

    printf("\nVoce quer extra de ingredientes a essa pizza? Isso vai incrementar o preco dela (S/N)\n");
    scanf(" %c", &resposta);
    getchar();
    resposta = toupper(resposta);

    if (resposta == 'S')
    {

        int qtdIng = ReadIngredientes(tamIng, listaIng);

        printf("\nEscolha o ID do ingrediente: ");
        scanf("%d", &escolhaIng);

        while (escolhaIng > 0 && escolhaIng <= *tamIng)
        {

            soma += listaIng[escolhaIng].preco;
            printf("\nEscolha o ID do ingrediente: ");
            scanf("%d", &escolhaIng);
        }
    }

    printf("\nO Preco final da pizza %-25s eh R$ %-5.2f\n", (*listaPizza)[idVender].nome, (*listaPizza)[idVender].preco + soma);

    for (int i = idVender; i < *tamPiz - 1; i++)
    {
        (*listaPizza)[i] = (*listaPizza)[i + 1];
    }

    (*tamPiz)--;
    *listaPizza = realloc(*listaPizza, (*tamPiz) * sizeof(pizzas));

    printf("\nPizza vendida com sucesso!\n");
}