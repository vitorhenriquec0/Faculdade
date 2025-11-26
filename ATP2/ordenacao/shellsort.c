#include <stdio.h>

void ShellSort(int v[], int n);

int main() {
    int v[] = {29, 32, 4, 3, 43, 5, 21, 90, 76};
    int n = 9;

    printf("\nVetor nao ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    ShellSort(v, n);

    printf("\nVetor ordenado por Shell Sort: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);
}

void ShellSort(int v[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = v[i];

            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}