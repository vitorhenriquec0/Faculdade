/*
Suponha que um vetor ordenado em ordem crescente foi rotacionado
em algum pivô desconhecido a você antecipadamente.
(Isto é, 0 1 2 4 5 6 7 pode ter se tornado 4 5 6 7 0 1 2).

Você recebe esse vetor rotacionado e um número inteiro alvo para procurar.
Se o alvo for encontrado no vetor, retorne o seu índice, caso contrário, retorne -1.
*/

#include <stdio.h>

int BuscaIndice(int v[], int n, int x);

int main() {
    int A[7] = {4, 5, 6, 7, 0, 1, 2};
    int n = 7;

    int x;
    scanf("%d", &x);

    int index = BuscaIndice(A, n, x);
    printf("Indice: %d", index);

    return 0;
}

int BuscaIndice(int v[], int n, int x) {
    int e = 0;
    int d = n - 1;

    while (e <= d) {
        int m = (e + d) / 2;

        if (v[m] == x) return m;

        if (v[e] <= v[m]) { // lado esquerdo ordenado
            if (v[e] <= x && x <= v[m]) {
                d = m - 1;
            } else {
                e = m + 1;
            }
        } else {
            if (v[m] <= x && x <= v[d]) {
                e = m + 1;
            } else {
                d = m - 1;
            }
        }
    }

    return -1;

}