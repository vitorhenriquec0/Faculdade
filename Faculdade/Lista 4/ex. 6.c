#include <stdio.h>

int main () {
    
    int n, i;
    unsigned long long fatorial = 1;
    
    printf("Digite o numero inteiro positivo:");
    scanf("%d", &n);
    
    for (i = 1; i<=n; ++i) {
        fatorial *= i;
    }
    
    printf("Fatorial de %d = %llu", n, fatorial);
    
    return 0;
}