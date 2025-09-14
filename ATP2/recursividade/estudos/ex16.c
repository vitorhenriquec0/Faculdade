/*
Crie um programa que contenha uma func¸ao recursiva para encontrar o menor elemento ˜
em um vetor.
*/

#include <stdio.h>

int menorElemento(int vetor[], int tamanho, int indice);

int main() {
    int vetor[] = {1, 89, 34, 76, 4, 2};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    printf("Menor elemento do vetor: %d", menorElemento(vetor, n, 0));

    return 0;
}

int menorElemento(int vetor[], int tamanho, int indice) {
    if (indice == tamanho - 1) return vetor[indice];
    int elementoAtual = vetor[indice];

    int menor = menorElemento(vetor, tamanho, indice + 1);

    if (elementoAtual < menor) {
        return elementoAtual;
    } else {
        return menor;
    }
}