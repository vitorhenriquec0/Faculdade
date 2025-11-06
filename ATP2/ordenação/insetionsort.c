#include <stdio.h>

void Insert (int n, int v[]);

int main() {
    int v[] = {29, 10, 14, 37, 13};
    int n = 5;

    printf("Vetor desordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    Insert(n, v);

    printf("\n\nVetor ordenado: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}

void Insert(int n, int v[]) {
    int i, j, x;

    for (j = 1; j < n; j++) {
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; i--) {
            v[i+1] = v[i];
        }
        v[i+1] = x;
    }
}