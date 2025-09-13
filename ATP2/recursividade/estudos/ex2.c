// Imprimir do 0 ao numero n

#include <stdio.h>
#include <stdlib.h>

void imprimir(int atual, int n);

int main() {
    int n;
    scanf("%d", &n);

    imprimir(0, n);
    return 0;
}

void imprimir(int atual, int n) {
    if (atual == n) {
        printf("%d", n);
    } else {
        printf("%d ", atual);
        imprimir(atual + 1, n);
    }
}