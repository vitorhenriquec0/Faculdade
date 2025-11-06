/*
⋆) Crie uma função que receba uma matriz A ∈ Rm×n
e dois números inteiros m e n, e
que transponha a matriz A, retornando a matriz A
T alocada dinamicamente.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **transposta(int **matriz, int m, int n);

int main() {

    srand(time(NULL));

    int **matriz;
    int m, n;

    scanf("%d %d", &m, &n);

    matriz = malloc(m * sizeof(int*));
    for (int i = 0; i < m; i++) {
        *(matriz + i) = malloc(n * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(*(matriz + i) + j) = rand() % 51;
        }
    }

    printf("\nMatriz Original:\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(*(matriz + i) + j));
        }
        printf("\n");
    }

    int **matrizT = transposta(matriz, m, n);

    printf("\nMatriz Transposta:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrizT[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) free(matriz[i]);
    free(matriz);
    for (int i = 0; i < n; i++) free(matrizT[i]);
    free(matrizT);

    return 0;
}

int **transposta(int **matriz, int m, int n) {
    int **matT = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matT[i] = malloc(m * sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matT[j][i] = matriz[i][j];
        }
    }

    return matT;
}
