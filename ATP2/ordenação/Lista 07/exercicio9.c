/*
Dado um vetor A ∈ A com N elementos, construa um algoritmo de ordenação
FREQSORT(A) que retornará o vetor A ordenado de maneira decrescente
com base na frequência dos elementos.
*/

#include <stdio.h>

void freqSort(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int freqI = 0, freqJ = 0;

            for (int k = 0; k < n; k++) {
                if (v[k] == v[i]) freqI++;
            }

            for (int k = 0; k < n; k++) {
                if (v[k] == v[j]) freqJ++;
            }

            if (freqI < freqJ || (freqI == freqJ && v[i] > v[j])) {
                int temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
}

int main() {
    int v[] = {5, 7, 7, 1, 5, 3, 5, 5, 1};
    int n = 9;

    freqSort(v, n);

    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}