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
    char x;
    pizzaId++;
    *tamPiz += 1;
    *listaPizza = realloc(*listaPizza, sizeof(pizzas) * (*tamPiz));
    if (*listaPizza == NULL) {
        printf("Erro de memória ao adicionar pizza!\n");
        exit(1);
    }
    pizzas *novaPizza = &((*listaPizza)[*tamPiz - 1]);
    novaPizza->id = pizzaId;
    
    menuCriar(menuPiz);
    printf("\n| Nome: ");
    scanf(" %[^\n]", novaPizza->nome);
    getchar();
    printf("| Tamanho (P, M, G): ");
    scanf("%c", &novaPizza->tamanho);
    novaPizza->tamanho = toupper(novaPizza->tamanho);
    getchar();
    printf("| Preço: ");
    scanf("%f", &novaPizza->preco);
    getchar();
    printf("|----------------------------------------|");
    printf("\n|  Exibr os Ingredientes antes? [ S/N ]  |\n|  ");
    scanf(" %c", &x);
    getchar();
    
    if(toupper(x) == 'S'){
        ReadIngredientes(tamIng, listaIng, menuPiz);
    }

    novaPizza->num_ingredientes = 0;

    menuCriar(menuPiz);
    printf("\n|  Escolha até 10 Ingredientes da Pizza  |");
    printf("\n|  Digite um ID inválido para concluir   |");
    printf("\n|----------------------------------------|");
    printf("\n|    Escolha os IDs dos Ingredientes:    |\n");

    int escolhaIng;
    while (novaPizza->num_ingredientes < 10)
    {
        printf("| ");
        scanf("%d", &escolhaIng);
        getchar();

        if (escolhaIng < 0 || escolhaIng >= *tamIng)
        {
            break;
        }

        novaPizza->ing[novaPizza->num_ingredientes] = listaIng[escolhaIng];
        novaPizza->num_ingredientes++;
    }
    printf("|----------------------------------------|");
    printf("\n|     Pizza adicionada com sucesso!      |");
    printf("\n|  Exibir os Ingredientes adicionados?   |");
    printf("\n|               [ S/N ]                  |");
    printf("\n|----------------------------------------|\n ");
    scanf(" %c", &x);
    getchar();
    x = toupper(x);
    if(x == 'S'){
        menu m;
        strcpy(m.nomeItem, "Pizza");
        tamIng != 0 && listaIng != NULL ? ReadIngredientes(&novaPizza->num_ingredientes, novaPizza->ing, m) : 0;
    }

}

int ReadPizza(int *tamPiz, pizzas **listaPizza)
{
    menuPiz.operacao[0] = 'R';
    menuPiz.item[0] = 'P';
    char resposta;
    int respostaId;
    int i;
    
    menuCriar(menuPiz);
    printf("\n|    |               |       |           |");
    printf("\n| %-2s | %-13s | %-5s | %-10s |", "ID", "     Nome"," Tam.", " Preço");
    printf("\n|    |               |       |           |");
    printf("\n|----------------------------------------|");
    for (i = 0; i < *tamPiz; i++)
    {
        printf("\n| %-2d | %-13s |   %-3c | R$ %-6.2f |", i, (*listaPizza)[i].nome, (*listaPizza)[i].tamanho, (*listaPizza)[i].preco);
    }
    if(i==0){
        printf("\n|       Nenhuma Pizza encontrada!        |");
    }
    printf("\n|----------------------------------------|");
    printf("\n|  Exibir Ingredientes de alguma Pizza?  |");
    printf("\n|               [ S/N ]                  |");
    printf("\n|----------------------------------------|\n| ");
    scanf(" %c", &resposta);
    getchar();

    resposta = toupper(resposta);

    if (resposta == 'S')
    {
        menu m;
        strcpy(m.nomeItem, "Pizza");
        printf("| Digite o ID da Pizza: ");
        if (scanf("%d", &respostaId) != 1) {
            while(getchar() != '\n'); // limpar stdin
            printf("ID inválido (entrada não numérica).\n");
            return *tamPiz;
        }
        getchar();

        if (respostaId < 0 || respostaId >= *tamPiz) {
            printf("ID fora do intervalo (0..%d).\n", *tamPiz - 1);
            return *tamPiz;
        }

        // Verifica se a pizza tem ingredientes válidos
        pizzas *p = &(*listaPizza)[respostaId];
        if (p->num_ingredientes <= 0 || strcmp(p->ing[0].nome, "") == 0) {
            printf("Essa pizza não possui ingredientes registrados.\n");
            return *tamPiz;
        }

        ReadIngredientes(&p->num_ingredientes, p->ing, m);
    }

    return *tamPiz;
}

void UpdatePizzas(pizzas *piz, ingrediente *listaIng, int *tamIng)
{
    menuPiz.operacao[0] = 'U';
    menuPiz.item[0] = 'P';
    int escolhaTipo;
    char nomeEdit[50], tamanhoEdit[10], x;
    float precoEdit;

    menuCriar(menuPiz);
    printf("\n|  Insira -1 para manter o valor antigo  |");
    printf("\n|----------------------------------------|");
    printf("\n| Nome: ");
    scanf(" %[^\n]", nomeEdit);
    strcmp(nomeEdit, "-1") != 0 ? strcpy((piz)->nome,nomeEdit) : 0;
    getchar();
    printf("| Tamanho (P, M, G): ");
    scanf("%s", tamanhoEdit);
    tamanhoEdit[0] = toupper(tamanhoEdit[0]);
    tamanhoEdit[0] == 'P' || tamanhoEdit[0] == 'M' || tamanhoEdit[0] == 'G' ? (piz)->tamanho = tamanhoEdit[0] : 0; 
    getchar();
    printf("| Preço: R$ ");
    scanf("%f", &precoEdit);
    precoEdit != -1 ? (piz)->preco = precoEdit : 0;
    getchar();
    printf("|----------------------------------------|");
    printf("\n|    Exibir os Ingredientes da Pizza?    |");
    printf("\n|               [ S/N ]                  |");
    printf("\n|----------------------------------------|\n ");
    scanf(" %c", &x);
    getchar();
    x = toupper(x);
    if(x == 'S'){
        menu m;
        strcpy(m.nomeItem, "Pizza");
        (piz)->num_ingredientes != 0 ? ReadIngredientes(&(piz)->num_ingredientes, (piz)->ing, m) : 0;
    }
    printf("|----------------------------------------|");
    printf("\n|   Você quer editar os Ingredientes?    |");
    printf("\n|               [ S/N ]                  |");
    printf("\n|----------------------------------------|\n ");
    scanf(" %c", &x);
    getchar();
    x = toupper(x);
    if(x == 'S'){

        menuCriar(menuPiz);
        printf("\n|  Escolha até 10 Ingredientes da Pizza  |");
        printf("\n|  Digite um ID inválido para concluir   |");
        printf("\n|----------------------------------------|");
        printf("\n|    Escolha os IDs dos Ingredientes:    |\n");

        int escolhaIng;
        piz->num_ingredientes = 0;

        while((piz)->num_ingredientes < 10){
            printf("| ");
            scanf("%d", &escolhaIng);
            getchar();

            if (escolhaIng < 0 || escolhaIng >= *tamIng)
            {
                break;
            }

            (piz)->ing[(piz)->num_ingredientes] = listaIng[escolhaIng];
            (piz)->num_ingredientes++;
        }

    }
    printf("|----------------------------------------|\n");
    printf("|     Pizza atualizada com sucesso!      |\n");
    printf("|                                        |\n");
    printf("|  Pressione [ ENTER ] para continuar.   |\n");
    printf("|----------------------------------------|\n ");
    getchar();

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

    ReadPizza(tamPiz, listaPizza);

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