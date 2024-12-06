README - Trabalho de CRUD em C para Pizzaria QUIJU 🍕

Este projeto foi desenvolvido como parte de um trabalho de programação em linguagem C. Ele implementa um sistema CRUD (Criar, Ler, Atualizar, Deletar) para gerenciar pizzas e seus ingredientes.

Dupla

Felipe Quites
Julia Santos


Descrição do Projeto

O sistema permite realizar as seguintes operações:

Adicionar novas pizzas ou ingredientes.
Listar (ler) todos os dados cadastrados.
Editar pizzas ou ingredientes existentes.
Deletar pizzas ou ingredientes do sistema.
O programa utiliza alocação dinâmica de memória para gerenciar os arrays de pizzas e ingredientes, proporcionando flexibilidade no gerenciamento dos dados.

Estrutura do Projeto

O projeto está dividido em arquivos modulares para facilitar a manutenção e organização:

main.c: Arquivo principal, que gerencia a interação com o usuário e as chamadas às funções do CRUD.
Headers/ingrediente.h: Declarações relacionadas à estrutura e manipulação de ingredientes.
Headers/pizza.h: Declarações relacionadas à estrutura e manipulação de pizzas.
Modulos/ingrediente.c: Implementação das funções relacionadas a ingredientes.
Modulos/pizza.c: Implementação das funções relacionadas a pizzas.
Como Compilar

Para compilar o projeto, utilize o seguinte comando no terminal (certifique-se de estar na raiz do diretório):

gcc main.c Modulos/ingrediente.c Modulos/pizza.c -o trabalho
Como Executar

Após a compilação, o executável gerado pode ser executado com o comando:

./trabalho
Funcionalidades

Menu Principal
O programa apresenta as opções:

C: Criar pizzas ou ingredientes.
R: Ler pizzas ou ingredientes cadastrados.
U: Atualizar informações de pizzas ou ingredientes.
D: Deletar pizzas ou ingredientes.
Estrutura de Dados
Ingredientes:
Nome
Preço
ID
Pizzas:
Nome
Tamanho
Preço
Lista de Ingredientes
