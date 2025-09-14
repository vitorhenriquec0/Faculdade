// Converter numeros de base 10 para binario

#include <stdio.h>
#include <stdlib.h>

void binario(int n);

int main() {
    int n;
    scanf("%d", &n);

    binario(n);

    return 0;
}

void binario(int n) {
    if (n == 0) {
        printf("%d", n);
    } else {
        binario(n/2);
        printf("%d", n % 2);
    }
}