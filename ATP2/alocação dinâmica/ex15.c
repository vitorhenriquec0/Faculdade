/*
Crie um programa que receba quatro números inteiros m, n, p e q e duas matrizes A
e B de tamanhos m × n e p × q, respectivamente. Além disso, receba os elementos dessas
matrizes a partir da entrada padrão. Em seguida, realize os seguintes itens:
a) Imprima a soma dessas matrizes: A + B.
b) Imprima a subtração dessas matrizes: A − B.
c) Imprima a multiplicação dessas matrizes: AB.
d) Imprima a transposta da matriz A
e) Imprima a transposta da matriz B
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int m, n, p, q;
    int **A, **B;

    scanf("%d%d%d%d", &m, &n, &p, &q);

    A = calloc(m, sizeof(int *));
    B = calloc(p, sizeof(int *));

    if (A == NULL || B == NULL) {
        printf("Erro de alocação de memória. \n");
        exit(1);
    }

    for (int i = 0; i < m; i++) {
        A[i] = calloc(n, sizeof(int));
    }

    for (int i = 0; i < p; i++) {
        B[i] = calloc(q, sizeof(int));
    }

    // a) Soma das matrizes

    if (m != p || n != q) {
        printf("\nAs matrizes não podem ser somadas ou subtraídas");
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", *(*(A + i) + j) + *(*(B + i) + j));
            }
            printf("\n");
        }
    }

    // b) Subtração das matrizes

    if (m != p || n != q) {
        printf("\nAs matrizes não podem ser somadas ou subtraídas");
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", *(*(A + i) + j) - *(*(B + i) + j));
            }
            printf("\n");
        }
    }

    // c) Multiplicação das matrizes

    int somatório ;
    if (n == p) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < p; k++) {

                }
            }
        }
    }
}