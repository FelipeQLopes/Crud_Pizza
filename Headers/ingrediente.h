#ifndef INGREDIENTE_H
#define INGREDIENTE_H

typedef struct ingrediente {
    int id;
    char nome[50];
    float preco;
} ingrediente;

void AddIngredientes(ingrediente** listaIng, int* tamIng);
int ReadIngredientes(int* tamIng, ingrediente* listaIng);
void UpdateIngredientes(ingrediente* ing);
void DeleteIngredientes(ingrediente** listaIng, int* tamIng);

#endif