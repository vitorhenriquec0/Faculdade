// Atividade ED1

// Mariana Elias
// Vítor Henrique Cardoso

#ifndef ABC_H
#define ABC_H

#include <stdio.h>
#include <stdlib.h>

// um limite máximo para poder usar no registro (struct)
#define MAX 100 

typedef struct {
    int nos[MAX];
    int tamanho;
} ABC;

void carregarABC(ABC* arvore, int h);

void preOrdem(ABC* arvore, int i);

void emOrdem(ABC* arvore, int i);

void posOrdem(ABC* arvore, int i);

#endif