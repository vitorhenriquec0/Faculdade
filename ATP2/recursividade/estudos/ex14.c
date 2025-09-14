/*
Fac¸a uma func¸ao recursiva que receba um n ˜ umero inteiro positivo par N e imprima todos ´
os numeros pares de 0 at ´ e N em ordem crescente.
*/

#include <stdio.h>

void imprimirPares(int n, int inicio);

int main() {
    int n;
    scanf("%d", &n);

    imprimirPares(n, 0);

    return 0;
}

void imprimirPares(int n, int inicio) {
    if (inicio > n) return;
    if (inicio % 2 == 0) printf("%d ", inicio);
    imprimirPares(n, inicio + 1);
}
