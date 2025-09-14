/*
Implemente uma função recursiva em C que receba um vetor de inteiros, seu tamanho
n e um número escalar, e retorne um novo vetor, alocado dinamicamente, contendo os
elementos do vetor original somado pelo elemento na posição anterior do novo vetor e
multiplicados pelo escalar: v_novo[i] = (v[i] + v_novo[i − 1]) ∗ escalar. Note que o último
elemento do novo vetor v_novo[n − 1] = v[n − 1]. A função deve usar recursão para per-
correr o vetor e preencher o novo vetor resultante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void alocacao(int **vetor, int n);

void preencher(int *vetor, int n);

void imprimir(int *vetor, int n);

void recursao(int *vetor, int *newVetor, int n, int escalar, int i);

int main() {
    
    srand(time(NULL));
    
    int n;
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &n);
    
    int *vetor;
    
    alocacao(&vetor, n);
    
    preencher(vetor, n);
    
    printf("\nVetor original: ");
    
    imprimir(vetor, n);
    
    int *newVetor;
    int escalar;
    printf("\n\nDigite o numero escalar: ");
    scanf("%d", &escalar);
    
    alocacao(&newVetor, n);
    recursao(vetor, newVetor, n, escalar, 0);
    
    imprimir(newVetor, n);
    
    free(vetor);
    free(newVetor);
    
    return 0;
    
}

void alocacao(int **vetor, int n) {
    *vetor = malloc(n * sizeof(int));
    if(*vetor == NULL) {
        printf("Erro na alocacao de memoria");
        return;
    }
}

void preencher(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        *(vetor + i) = rand() % 31;
    }
}

void imprimir(int *vetor, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(vetor + i));
    }
}

void recursao(int *vetor, int *newVetor, int n, int escalar, int i) {
    if (i == n - 1) {
        newVetor[i] = vetor[i];
        return;
    }
    if (i == 0) {
        newVetor[i] = (vetor[i]) * escalar;
    } else {
        newVetor[i] = (vetor[i] + newVetor[i - 1]) * escalar;
    }
    recursao(vetor, newVetor, n, escalar, i + 1);
}