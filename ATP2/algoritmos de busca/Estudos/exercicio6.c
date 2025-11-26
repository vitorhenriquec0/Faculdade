/*
Implemente um algoritmo para determinar se um vetor $V$ de $N$ inteiros estritamente
crescentes possui um ponto fixo. Um ponto fixo é um elemento onde o valor armazenado
é igual à sua posição no vetor ($V[x] = x$).
Caso existam múltiplos pontos fixos (embora improvável com a restrição de "estritamente crescente"
em certos intervalos), retorne qualquer um deles, ou -1 se nenhum existir. Utilize a abordagem de Divisão e Conquista.
*/

#include <stdio.h>

int BinarySearchIndexMatch(int v[], int n);

int main() {
    int A[6] = {0, 2, 4, 6, 8, 10};
    int n = 6;

    int res = BinarySearchIndexMatch(A, n);
    printf("%d", res);

    return 0;
}

int BinarySearchIndexMatch(int v[], int n) {
    int e = 0;
    int d = n - 1;

    while (e <= d) {
        int m = (e + d) / 2;

        if (v[m] == m) return m;
        if (v[m] > m) {
            d = m - 1;
        } else {
            e = m + 1;
        }
    }

    return -1;
}