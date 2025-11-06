/*
Faca uma funcao recursiva que receba um n´umero inteiro positivo N e retorne o hiperfa
torial desse n´umero.
*/

#include <stdio.h>

int potencia(int n, int e);

int hiperFatorial(int n);

int main() {
    int n;
    scanf("%d", &n);

    printf("Hiperfatorial de %d: %d", n, hiperFatorial(n));

    return 0;
}

int potencia(int n, int e) {
    if (e == 0) return 1;
    return n * potencia(n, e - 1);
}

int hiperFatorial(int n) {
    if (n == 0) return 1;
    return hiperFatorial(n - 1) * potencia(n, n);
}


