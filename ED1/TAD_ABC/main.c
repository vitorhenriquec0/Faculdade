// Atividade ED1

// Mariana Elias
// Vítor Henrique Cardoso

#include <stdio.h>
#include "ABC.h"

int main() {
    ABC arvore;
    arvore.tamanho = 0;
    int altura;

    printf("Digite a altura da ABC: ");
    scanf("%d", &altura);

    carregarABC(&arvore, altura);

    preOrdem(&arvore, 1);
    printf("\n");

    emOrdem(&arvore, 1);
    printf("\n");

    posOrdem(&arvore, 1);

    return 0;
}