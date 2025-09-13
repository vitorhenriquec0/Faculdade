// Implemente uma função recursiva somatoria de 1 a N

#include <stdio.h>
#include <stdlib.h>

int somatorio(int n);

int main() {
    int n;
    scanf("%d", &n);

    printf("A soma de  1 ate %d eh: %d", n, somatorio(n));
    
    return 0;
}

int somatorio(int n) {
    if (n == 0) return 0;
    return n + somatorio(n - 1);
}