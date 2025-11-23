/*
Você recebe um vetor de inteiros ordenado, onde todos os números
aparecem exatamente duas vezes, exceto um elemento que aparece
apenas uma vez. Encontre esse elemento solitário.
*/

#include <stdio.h>

void BuscaElemento(int v[], int n);

int main() {
    int A[9] = {0, 0, 1, 1, 2, 3, 3, 4, 4};
    int n = 9;

    BuscaElemento(A, n);

    return 0;
}

void BuscaElemento(int v[], int n) {
    int e = 0;
    int d = n - 1;

    while (e < d) {
        int m = (e + d) / 2;

        if (m % 2 != 0) m--; // ajustar p ficar {par, impar}
        
        int elem1 = v[m];
        int elem2 = v[m+1];

        if (elem1 == elem2) {
            e = m + 2;
        } else {
            d = m;
        }
    }

    printf("Elemento: %d", v[d]);
}