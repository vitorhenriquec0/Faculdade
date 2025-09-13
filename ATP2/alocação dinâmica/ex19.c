/*
Crie um programa que receba dois números inteiros m e n, que receba as entradas
de uma matriz A de tamanho m × n, e que imprima na saída padrão da aplicação essa
matriz. Entretanto, nesse exercício você está encarregado de implementar essa matriz
como um vetor simples alocado dinamicamente (e não como um vetor de vetores).
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    int m, n;
    int *A;

    scanf("%d%d", &m, &n);

    A = calloc(m * n, sizeof(int));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[i * n + j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i * n + j]);
        }
        printf("\n");
    }

    return 0;
}