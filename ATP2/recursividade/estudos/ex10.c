// Inverter os elementos de um vetor

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inverter(int *vetor, int ini, int fim);
void imprimir(int *vetor, int tam, int indice);

int main() {
    int tam;
    scanf("%d", &tam);

    int *vetor;
    vetor = malloc(tam * sizeof(int));

    for (int i = 0; i < tam; i++) {
        *(vetor + i) = rand() % 30;
    }

    printf("\nVetor original:");
    imprimir(vetor, tam, 0);

    inverter(vetor, 0, tam);

    printf("\nVetor invertido:");
    imprimir(vetor, tam, 0);

    return 0;
}

void inverter(int *vetor, int indice, int tam) {
    int aux;
    if(indice < tam) {
        aux = vetor[indice];
        vetor[indice] = vetor[tam - 1];
        vetor[tam - 1] = aux;
        inverter(vetor, indice + 1, tam - 1);
    }
}

void imprimir(int *vetor, int tam, int indice) {
    if (indice == tam) return;
    printf(" %d", *(vetor + indice));
    imprimir(vetor, tam, indice + 1);
}