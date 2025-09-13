// Função que calcula o fatorial de n

#include <stdio.h>
#include <stdlib.h>

int fatorial(int n);

int main() {
    int n;
    scanf("%d", &n);

    printf("Fatorial de %d: %d", n, fatorial(n));

    return 0;
}

int fatorial(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fatorial(n - 1);
}