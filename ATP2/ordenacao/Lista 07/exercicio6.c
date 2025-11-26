/*
1.6. Implemente o algoritmo de ordenação QUICKSORT(A) utilizando um pivô tanto crescente
 tanto decrescente.
*/

#include <stdio.h>

int Separa(int p, int r, int v[]);

void QuickSort(int p, int r, int v[]);

int main() {

    int v[] = {89, 29, 43, 19, 2, 8, 9, 15};
    int n = 8;

    printf("\nVetor nao ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    QuickSort(0, n - 1, v);

    printf("\n\nVetor ordenado por Quick Sort: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    return 0;

}

int Separa(int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r];
    j = p;

    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
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

/*
int Separa(int p, int r, int v[]) {
    int c, j, k, t;
    c = v[r];
    j = p;

    for (k = p; k < r; k++) {
        if (v[k] >= c) {
            t = v[j];
            v[j] = v[k];
            v[k] = t;
            j++;
        }
    }
    v[r] = v[j];
    v[j] = c;

    return j;
}
*/