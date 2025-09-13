// Calcular a sequencia de fibonnaci de um numero n

#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main() {
    int n;
    scanf("%d", &n);

    printf("Numero %d na sequencia de Fibonacci: %d", n, fibonacci(n));
    return 0;
}

int fibonacci(int n) {
    if (n == 1) return 0;
    if (n == 2) return 1;
    return fibonacci(n - 2) + fibonacci(n - 1);
}