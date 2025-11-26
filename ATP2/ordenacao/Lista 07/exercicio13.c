/*
 Implemente um programa que receba um vetor A∈RN e um número natural k∈N,
 imprimindo na saída padrão da aplicação os k menores elementos de A.
 Note: Você deve usar, obrigatoriamente, um algoritmo de ordenação.

 -> Utilizarei o Quick Sort para ordenar o vetor, mas poderia ser
    outro algoritmo.
 -> Após ordenado, basta imprimir os k menores elementos do vetor.
*/

#include <stdio.h>

int Separa(int p, int r, int v[]);

void QuickSort(int p, int r, int v[]);

int main() {
    int n;
    scanf("%d", &n);

    int k;
    scanf("%d", &k);

    int vetor[n];
    for (int i = 0; i < n; i++) scanf("%d", &vetor[i]);

    printf("\n\nVetor original: ");
    for (int i = 0; i < n; i++) printf("%d ", vetor[i]);

    QuickSort(0, n - 1, vetor);

    printf("\n\nOs %d menores elementos do vetor: ", k);
    for (int i = 0; i < k; i++) printf("%d ", vetor[i]);

}

int Separa(int p, int r, int v[]) {
    int c, j, k, temp;
    c = v[r];
    j = p;

    for (k = p; k < r; k++) {
        if (v[k] <= c) {
            temp = v[j];
            v[j] = v[k];
            v[k] = temp;
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

