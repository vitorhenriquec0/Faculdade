/*
 1.5. Implemente o algoritmo de ordenação MERGESORT(A) tanto crescente tanto decrescente.
*/

// -> Decrescente

#include <stdio.h>
#include <stdlib.h>

void Intercala(int p, int q, int r, int v[]);
void MergeSort(int p, int r, int v[]);

int main() {
    int v[] = {89, 29, 43, 19, 2, 8, 9, 15};
    int n = 8;

    printf("\nVetor nao ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    MergeSort(0, n, v);

    printf("\n\nVetor ordenado por Merge Sort: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    return 0;
}

void Intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));

    i = p;
    j = q;
    k = 0;

    while (i < q && j < r) {
        if (v[j] > v[i]) w[k++] = v[j++];
        else w[k++] = v[i++];
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