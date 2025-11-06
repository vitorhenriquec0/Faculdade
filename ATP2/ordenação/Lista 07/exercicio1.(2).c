/*
 1.1. Implemente o algoritmo de ordenação BUBBLESORT(A) tanto crescente tanto decrescente.
*/

#include <stdio.h>

void BubbleSortDecrescente (int n, int v[]);

int main() {
    int v[] = {29, 32, 4, 3, 43, 5, 21, 90, 76};
    int n = 9;

    printf("\nVetor nao ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    BubbleSortDecrescente(n, v);

    printf("\nVetor ordenado por Bubble Sort: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
}

void BubbleSortDecrescente (int n, int v[]) {
    int i, j, temp;

    for (i = n - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (v[j] < v[j + 1]) {
                temp = v[j + 1];
                v[j + 1] = v[j];
                v[j] = temp;
            }
        }
    }
}