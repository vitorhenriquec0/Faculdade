/*
 1.3. Implemente oalgoritmo de ordenação INSERTIONSORT(A) tanto crescente tanto decrescente.
*/

#include <stdio.h>

void InsertionSort(int n, int v[]);

int main() {

    int v[] = {98, 32, 4, 2, 78, 44, 9};
    int n = 7;

    printf("\nVetor nao ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    InsertionSort(n, v);

    printf("\n\nVetor ordenado por selection sort: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    return 0;

}

void InsertionSort(int n, int v[]) {
    int i, j, x;
    for (j = 1; j < n; j++) {
        x = v[j];

        i = j - 1;
        while (i >= 0 && v[i] > x) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = x;
    }
}