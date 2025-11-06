/*
Fac¸a uma func¸˜ ao recursiva que receba um n´umero inteiro positivo N e retorne o super
fatorial desse n´umero. O superfatorial de um n´umero N ´ e definida pelo produto dos N
 primeiros fatoriais de N.
*/

#include <stdio.h>

int fatorial(int n);

int superFatorial(int n);

int main() {
    int n;
    scanf("%d", &n);

    printf("Super fatorial de %d: %d", n, superFatorial(n));

    return 0;
}

int fatorial(int n) {
    if (n == 0) return 1;
    return n * fatorial(n - 1);
}

int superFatorial(int n) {
    if (n == 0) return 1;
    return fatorial(n) * superFatorial(n - 1);
}