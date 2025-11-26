/*
 Construa um programa tal que receba uma matriz M∈Rm×n, e usando algum algoritmo
 de ordenação que desejar, imprima na saída padrão da aplicação a matriz com cada linha
 ordenada

 --> MERGE SORT
*/

#include <stdio.h>
#include <stdlib.h>

void Intercala(int p, int q, int r, int v[]);

void MergeSort(int p, int r, int v[]);

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
        MergeSort(0, n, mat[i]);
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

void Intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));
    i = p; j = q; k = 0;

    while (i < q && j < r) {
        if (v[i] <= v[j]) w[k++] = v[i++];
        else w[k++] = v[j++];
    }

    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];

    for (i = p; i < r; i++) v[i] = w[i - p];
    free(w);
}

void MergeSort(int p, int r, int v[]) {
    if (p < r - 1) {

        int q = (p + r) / 2;

        MergeSort(p, q, v);
        MergeSort(q, r, v);
        Intercala(p, q, r, v);
    }
}
