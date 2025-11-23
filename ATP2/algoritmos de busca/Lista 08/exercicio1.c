/*
Construa um programa que receba um vetor de números inteiros A ∈ ZN com N elemen
tos, e um número inteiro k ∈ Z, e usando o algoritmo de BUSCALINEAR(A, X) imprima na
saída padrão da aplicação a posição de k em A caso k ∈ A. Caso contrário, imprima −1.
*/

#include <stdio.h>

int BuscaLinear(int v[], int n, int x);

int main () {
    int v[7] = {3, 5, 10, 15, 17, 19, 25};
    int n = 7;
    int x;

    scanf("%d", &x);

    int resultado = BuscaLinear(v, n, x);
    printf("%d", resultado);

    return 0;
}

int BuscaLinear(int v[], int n, int x) {
 
    for (int i = 0; i < n; i++) {
        if (v[i] == x) return i;
    }

    return - 1;
}