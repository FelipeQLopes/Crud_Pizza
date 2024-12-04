#include <stdio.h>
#include "Modulos/ingrediente.c"
#include "Modulos/pizza.c"
#include "Headers/pizza.h"

int main(){
    
    char escolha [10];

    printf("Bem-Vindo ao programa da Pizzaria QUIJU");

    printf("Para utilizar as funcoes do programa digite CREATE para adicionar tanto pizzas quanto ingredientes READ");
    printf(" para ler ingredientes ou pizzas, UPDATE para editar um dado, DELETE para deletar um ingrediente ou pizza\n");

    scanf("%s", escolha);

    for(int i = 0; i < sizeof(escolha); i++){
        escolha[i] = toupper(escolha[i]);
    }

    getchar();

    while(escolha == "CREATE" && escolha == "UPDATE" && escolha == "READ" && escolha == "DELETE"){

        printf("\n Voce quer fazer isso para um ingrediente ou para uma pizza? (ING) (PIZZA)")

    }


}