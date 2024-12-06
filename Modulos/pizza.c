#include "../Headers/pizza.h"
#include "../Headers/ingrediente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <string.h>

int pizzaId = 0;

void AddPizza(pizzas** listaPizza, int* tamPiz, ingrediente* listaIng, int* tamIng) {
    pizzaId++;
    int novoTam = *tamPiz + 1;

    pizzas* novaLista = realloc(*listaPizza, sizeof(pizzas) * novoTam);
    if (!novaLista) {
        printf("Erro ao realocar memória para pizzas.\n");
        return;
    }

    *listaPizza = novaLista;
    *tamPiz = novoTam;

    pizzas* novaPizza = &(*listaPizza)[novoTam - 1];
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
    if (!novaPizza->ing) {
        printf("Erro ao alocar memória para os ingredientes da pizza.\n");
        return;
    }
    novaPizza->num_ingredientes = 0;

    printf("\nAgora escolha até 10 ingredientes para sua pizza.\n");
    printf("(Escolha digitando o ID dos ingredientes, ou um ID inválido para finalizar):\n");

    int escolhaIng;
    while (novaPizza->num_ingredientes < 10) {
        printf("Escolha o ID do ingrediente: ");
        scanf("%d", &escolhaIng);

        if (escolhaIng < 0 || escolhaIng >= qtdIng) {
            break;
        }

        novaPizza->ing[novaPizza->num_ingredientes] = listaIng[escolhaIng];
        novaPizza->num_ingredientes++;
    }

    printf("Pizza adicionada com sucesso!\n");
}


int ReadPizza(int* tamPiz, pizzas* listaPizza) {
    char resposta;
    int respostaId;

    printf("\nVoce quer ver a lista de pizzas? (S/N)\n");
    scanf(" %c", &resposta);
    getchar();

    resposta = toupper(resposta);

    if (resposta == 'S') {
        for (int i = 1; i < *tamPiz; i++) {
            printf("ID: %-3.d, Pizza: %-25s, Tamanho: %-5.c Preco: R$ %-5.2f\n", listaPizza[i].id, listaPizza[i].nome, listaPizza[i].tamanho, listaPizza[i].preco);
        }
    }

    printf("\nVoce quer ver os ingredientes de alguma pizza? (S/N)\n");
    scanf(" %c", &resposta);
    getchar();

    resposta = toupper(resposta);

    if (resposta == 'S') {
        printf("\nDigite o ID da pizza que voce quer:\n");
        scanf("%d", &respostaId);
        for(int k = 0; k < listaPizza[respostaId].num_ingredientes; k++){

            printf("Ingrediente %2d: %-25s\n", k + 1, listaPizza[respostaId].ing[k].nome);

        }

    }

    return *tamPiz;
}

void UpdatePizzas(pizzas* piz){

    int escolhaTipo, qtdIngEdit;
    char nomeEdit[50], tamanhoEdit;
    float precoEdit;

    printf("\nDigite o numero do que voce quer editar desse ingrediente:\n");
    printf("\t1 para o NOME \t 2 para o TAMANHO \t 3 para o PRECO\n");
    scanf("%d", &escolhaTipo);

    switch(escolhaTipo){

        case 1:
            printf("Digite o novo nome:\n");
            scanf(" %[^\n]", nomeEdit);
            strcpy(piz->nome, nomeEdit);
            printf("\nNome Atualizado com Sucesso!\n");

            break;

        case 2:
            printf("Digite o novo tamanho:");
            scanf("%c", &tamanhoEdit);
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


void DeletePizzas(pizzas* piz) {
    
    char* a = "DELETADO";

    piz->id = 0;
    strcpy(piz->nome,a);
    piz->tamanho = 0;
    piz->preco = 0;
    piz->num_ingredientes = 0;

    printf("\nPizza deletada com Sucesso!\n");
    
}


