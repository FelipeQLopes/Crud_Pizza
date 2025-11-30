# README - CRUD de Pizzas e Ingredientes 🍕

## Dupla

- **Felipe Quites**  
- **Julia Santos**

Este trabalho foi feito por **Felipe Quites** e **Julia Santos**, do projeto de AEDS

---

## Sobre o Projeto

Este programa implementa um sistema CRUD para gerenciar pizzas e ingredientes. Ele permite:  
- Adicionar pizzas ou ingredientes.  
- Ler pizzas ou ingredientes cadastrados.  
- Atualizar informações.  
- Deletar pizzas ou ingredientes.  

---

## Como Compilar e Executar

1. Compile o projeto com:  
   ```bash
   gcc main.c modulos/ingrediente.c modulos/pizza.c -o main
   ```

2. Execute o programa:  
   ```bash
   ./main
   ```

---

## Estrutura

- **Ingredientes**: Nome, Preço, ID.  
- **Pizzas**: Nome, Tamanho, Preço, Ingredientes.  
