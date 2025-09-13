// Implemente uma funcao para descobrir o maior elemento de um vetor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maior(int *vetor, int tam, int indice);

int main() {
    int tam;

    scanf("%d", &tam);

    int *vetor;

    srand(time(NULL));

    vetor = malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++) {
        *(vetor + i) = rand() % 30;
    }

    for (int i = 0; i < tam; i++) {
        printf("%d ", *(vetor + i));
    }

    printf("\n\nMaior elemento do vetor: %d", maior(vetor, tam, 0));

    return 0;
}

int maior(int *vetor, int tam, int indice) {
    if (tam == 0) {
        return vetor[indice];
    } else {
        if (vetor[tam] > vetor[indice]) {
            return maior(vetor, tam - 1, tam - 1);
        }
        else {
            return maior(vetor, tam - 1, indice);
        }
    }
}