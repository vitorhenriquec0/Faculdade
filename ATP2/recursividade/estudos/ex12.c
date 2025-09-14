/*
Escreva uma func¸ao recursiva que calcule a soma dos primeiros n cubos
*/

#include <stdio.h>

int somaCubos(int n);

int main() {
    int n;
    scanf("%d", &n);

    printf("Soma dos cubos de 1 a %d: %d", n, somaCubos(n));

    return 0;
}

int somaCubos(int n) {
    if (n == 1) return 1;
    return (n * n * n) + somaCubos(n - 1);
}