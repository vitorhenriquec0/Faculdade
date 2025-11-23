/*
Suponha que um vetor ordenado em ordem crescente foi rotacionado
em algum pivô desconhecido a você antecipadamente.
(Isto é, 0 1 2 4 5 6 7 pode ter se tornado 4 5 6 7 0 1 2).

Você recebe esse vetor rotacionado e tem que procurar a origem (ou seja, o menor elemento).
Retorne o seu índice.
*/

#include <stdio.h>

int BuscaBinaria(int v[], int n);

int main() {

    int A[7] = {4, 5, 6, 0, 1, 2, 3};
    int n = 7;

    int resultado = BuscaBinaria(A, n);
    printf("%d", resultado);

    return 0;
}

int BuscaBinaria(int v[], int n) {
    int e = 0;
    int d = n - 1;

    while (e < d) {
        int m = (e + d) / 2;

        if (v[m] > v[d]) {
            e = m + 1;
        } else {
            d = m;
        }
    }

    return d;
}