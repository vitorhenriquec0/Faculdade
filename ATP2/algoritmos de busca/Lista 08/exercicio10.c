/*
Construa um programa que receba um vetor A ∈ ZN com N números, inteiros e imprima
na saída padrão da aplicação todos os subconjuntos {a,b,c} ⊆ A, tal que a+b+c = 0.
*/

#include <stdio.h>

void ShellSort(int v[], int n);
void Triplets(int v[], int n);

int main() {

    int A[] = {-1, 0, 1, 2, -1, -4}; 
    int n = 6;
    
    Triplets(A, n);
    return 0;

}

void Triplets(int v[], int n) {
    ShellSort(v, n);

    for (int i = 0; i < n-2; i++) {
        if (v[i] > 0) break; // se o primeiro termo já é positivo, é impossivel dar 0

        if (i > 0 && v[i] == v[i-1]) continue; // evitar linhas duplicadas

        int L = i + 1;
        int R = n - 1;
        int obj = -v[i];

        while (L < R) {
            if (v[L] + v[R] == obj) {
                printf("{%d, %d, %d}\n", v[i], v[L], v[R]);
                L++;
                R--;
            } else if (v[L] + v[R] < obj) {
                L++;
            } else {
                R--;
            }
        }
    }
}

void ShellSort(int v[], int n) {
    int gap = 1;
    while (gap < n) gap = gap * 3 + 1;

    while (gap > 1) {
        gap /= 3;

        for (int i = gap; i < n; i++) {
            int temp = v[i];
            int j;

            for (j = i; j >= gap && v[j-gap] > temp; j-= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}