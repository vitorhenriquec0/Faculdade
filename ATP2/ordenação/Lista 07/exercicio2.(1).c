/*
 1.2. Implementeoalgoritmodeordenação SELECTIONSORT(A) tantocrescentetantodecrescente.
*/

#include <stdio.h>

void SelectionSort(int n, int v[]);

int main() {
    int v[] = {90, 32, 4, 32, 5};
    int n = 5;

    printf("\nVetor nao ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    SelectionSort(n, v);

    printf("\n\nVetor ordenado por selection sort: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    return 0;
}

void SelectionSort(int n, int v[]) {
    int i, j, min, x;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++) {
            if (v[j] < v[min]) min = j;
        }
        x = v[i]; v[i] = v[min]; v[min] = x;
    }
}