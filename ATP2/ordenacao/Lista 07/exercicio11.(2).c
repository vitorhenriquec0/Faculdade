/*
 Construa um programa tal que receba uma matriz M∈Rm×n, e usando algum algoritmo
 de ordenação que desejar, imprima na saída padrão da aplicação a matriz com cada linha
 ordenada

 --> SELECTION SORT
*/

#include <stdio.h>

void SelectionSort(int v[], int n);

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
        SelectionSort(mat[i], n);
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

void SelectionSort(int v[], int n) {
    int i, j, min, x;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = 1; j < n; j++) {
            if (v[j] < v[min]) min = j;
        }
        x = v[i]; v[i] = v[min]; v[min] = x;
    }
}