/*
 Construa um programa tal que receba uma matriz M∈Rm×n, e usando algum algoritmo
 de ordenação que desejar, imprima na saída padrão da aplicação a matriz com cada linha
 ordenada

 --> BUBBLE SORT
*/

#include <stdio.h>

void bubbleSort(int v[], int n);

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
        bubbleSort(mat[i], n);
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

void bubbleSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (v[j] > v[j + 1]) {
                int temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
            }
        }
    }
}