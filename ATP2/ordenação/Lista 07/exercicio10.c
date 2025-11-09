/*
 Dado um vetor A = ⟨a1,a2,...,aN⟩ ∈ RN com N elementos, construa um algoritmo de
 ordenação FREQSORT(A), tal que FREQSORT(A) = ⟨ak1,ak2, ..., akN⟩
 em que freq (ak1)≥freq(ak2)≥···≥freq(akN), com freq(ai) sendo o número
 de ocorrências de ai em A. Caso dois elementos ai e aj distintos possuam
 a mesma frequência, faça com que o que venha primeiro em A, também venha em primeiro em FREQSORT(A).
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

            if (freqI < freqJ) {
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