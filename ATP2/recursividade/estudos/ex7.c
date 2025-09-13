// Implemente uma funcao recursiva para somar todos elementos de um vetor

#include <stdio.h>
#include <stdlib.h>

int somatorio(int n[], int tam);

int main() {
    int vetor[3] = {20, 20, 40};

    printf("Somatorio do vetor: %d", somatorio(vetor, 3));

    return 0;
}

int somatorio(int n[], int tam) {
    if (tam == 0) return 0;
    return n[tam - 1] + somatorio(n, tam - 1);
}
