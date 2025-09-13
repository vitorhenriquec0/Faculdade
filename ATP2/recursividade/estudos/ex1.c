// Imprimir do numero n ao 0

#include <stdio.h>
#include <stdlib.h>

void imprimir(int n);

int main() {
    int n;
    scanf("%d", &n);

    imprimir(n);

    return 0;
}

void imprimir(int n) {
    if (n == 0) {
        printf(" %d", n);
    } else {
        printf(" %d", n);
        imprimir(n - 1);
    }
    
}