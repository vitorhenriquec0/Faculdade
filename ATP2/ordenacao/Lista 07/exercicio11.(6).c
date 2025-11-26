/*
 Construa um programa tal que receba uma matriz M∈Rm×n, e usando algum algoritmo
 de ordenação que desejar, imprima na saída padrão da aplicação a matriz com cada linha
 ordenada

 --> QUICK SORT
*/

#include <stdio.h>

int Separa(int p, int r, int v[]);

void QuickSort(int p, int r, int v[]);

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
        QuickSort(0, n - 1, mat[i]);
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

int Separa(int p, int r, int v[]) {
    int c, j, k, temp;
    c = v[r];
    j = p;
    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            temp = v[k];
            v[k] = v[j];
            v[j] = temp;
            j++;
        }
    }
    v[r] = v[j];
    v[j] = c;

    return j;
}

void QuickSort(int p, int r, int v[]) {
    int j;
    if (p < r) {
        j = Separa(p, r, v);
        QuickSort(p, j - 1, v);
        QuickSort(j + 1, r, v);
    }
}