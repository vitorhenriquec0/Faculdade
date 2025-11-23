/*
 Construa um programa tal que receba uma matriz M∈Rm×n, e usando algum algoritmo
 de ordenação que desejar, imprima na saída padrão da aplicação a matriz com cada linha
 ordenada

 --> SHELL SORT
*/

#include <stdio.h>

void ShellSort(int v[], int n);

int main() {
    int m, n;
    scanf("%d%d", &m, &n);

    int mat[m][n];
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\n-> Matriz desordenada:\n\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < m; i++) {
        ShellSort(mat[i], n);
    }

    printf("\n-> Matriz ordenada:\n\n");

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void ShellSort(int v[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = v[i];
            int j;

            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}