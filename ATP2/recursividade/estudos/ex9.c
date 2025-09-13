// Imprimir de forma inversa os elementos de um vetor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inverter(int *vetor, int tam);

int main() {
    int tam;
    scanf("%d", &tam);

    int *vetor;
    vetor = malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++) {
        *(vetor + i) = rand() % 30;
    }

    printf("\nVetor Original:");

    for (int i = 0; i < tam; i++) {
        printf(" %d", *(vetor + i));
    }

    printf("\nVetor Invertido:");
    inverter(vetor, tam);
    
    return 0;
}

void inverter(int *vetor, int tam) {
    if (tam == 0) return;
    printf(" %d", vetor[tam - 1]);
    inverter(vetor, tam - 1);
}

