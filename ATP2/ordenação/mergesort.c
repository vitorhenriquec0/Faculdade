#include <stdio.h>
#include <stdlib.h>

void Intercala(int p, int q, int r, int v[]);

void MergeSort(int p, int r, int v[]);


int main() {
    int vet[] = {90, 32, 43, 2, 45, 3, 2, 8 ,76};

    printf("\nVetor nao ordenado: ");
    for (int i = 0; i < 9; i++) printf("%d ", vet[i]);

    MergeSort(0, 9, vet);

    printf("\nVetor ordenado por Merge Sort: ");
    for (int i = 0; i < 9; i++) printf("%d ", vet[i]);
}

void Intercala(int p, int q, int r, int v[]) {
    int i, j, k, *w;
    w = malloc((r - p) * sizeof(int));

    i = p;
    j = q;
    k = 0;

    while (i < q && j < r) {
        if (v[i] < v[j]) w[k++] = v[i++];
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