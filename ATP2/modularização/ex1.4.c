/*
Crie uma função que receba duas matrizes A ∈ Rm×n e B ∈ Rn×p
e três números inteiros m, n e p, e que retorne à função
chamadora a matriz C ∈ Rm×p resultante da multiplicação das matrizes A e B.
Note: É necessário que a função chamada cheque se os argumentos são válidos.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void multiplicacaoMatrizes(int m, int n, int p, int matrizA[m][n], int matrizB[n][p], int matrizC[m][p]);

int main() {

    srand(time(NULL));

    int m, n, p;
    
    printf("Digite os valores de M, N e P:\n");
    scanf("%d%d%d", &m, &n, &p);

    int matrizA[m][n];
    int matrizB[n][p];
    int matrizC[m][p];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrizA[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            matrizB[i][j] = rand() % 10;
        }
    }

    multiplicacaoMatrizes(m, n, p, matrizA, matrizB, matrizC);

    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < p; j++) {
            printf("%d ", matrizC[i][j]);
        }
        printf("\n");
    }
}

void multiplicacaoMatrizes(int m, int n, int p, int matrizA[m][n], int matrizB[n][p], int matrizC[m][p]) {

    if (m <= 0 || n <= 0 || p <= 0) {
        printf("As dimensoes da matriz devem ser numeros inteiros positivos.");
        return 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            matrizC[i][j] = 0;
            for (int k = 0; k < n; k++) {
                matrizC[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}