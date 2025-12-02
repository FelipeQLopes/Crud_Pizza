# 🍕 Crud Pizza - Mini Sistema de Pizzaria 🍕

### Dupla:

- **Felipe Quites**  
- **Julia Santos**

## Sobre o Projeto

Este programa foi feito na matéria **AEDS I**, ele é um exemplo de um mini sistema para uma Pizzaria, ele permite a gestão de pizzas e ingredientes.

**Através de:** 
- **CREATE:** Cadastrar Ingredientes e Pizzas.  
- **READ:** Ler Ingredientes e Pizzas cadastrados.
- **UPDATE:** Atualizar informações dos Ingredientes e Pizzas.
- **DELETE:** Excluir os Ingredientes e Pizzas do sistema


## Como Compilar e Executar

1. Compile o projeto com:  
   ```
   make
   ```

2. Execute o programa com:  
   ```
   make run
   ```
   ou
   ```
   ./main
   ```

- Você pode também compilar e executar dessa forma:

   ```
   make crun
   ```

## **Estrutura**

### **Ingredientes:**

   `headers/ingrediente.h`
   `modulos/ingrediente.c`

- ID, Nome e Preço

      int id; // Sequencial
      char nome[50];
      float preco;

### **Pizzas:** 

   `headers/pizza.h`
   `modulos/pizza.c`
   
- ID, Nome, Tamanho, Preço, Ingredientes, Quantidade de Ingredientes  

      int id; // Sequencial
      char nome[50];
      char tamanho; // (P, M, G)
      float preco;
      ingrediente ing[10];
      int num_ingredientes;

### **Menu:**

   `headers/menu.h`
   `modulos/menu.c`
   
   Essa estrutura foi criada para gerenciar os menus do sistema e fazer um breadcrumb automaticamente

- Operação, Item, NomeItem, Breadcrumb

      char operacao[1]; // C R U D V
      char item[1]; // I, P --> Ingrediente, Pizza;
      char nomeItem[50];
      char breadcrumb[50];

### **Main:**

   `main.c`
   
   **Arquivo principal** do sistema que gerencia a leitura e o armazenamento de dados, além de gerir as funções principais da interação com o sistema

### **Armazenamento:**

   `dados/Ing.txt`
   `dados/Piz.txt`

   Nestes `txt`s estão armazenados os Ingredientes e Pizzas cadastrados respectivamente, permitindo o salvamento e leitura de dados **ao entrar e após sair do sistema**

<br>

---