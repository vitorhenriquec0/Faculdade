/*
Fac¸a uma func¸ao recursiva que receba um n ˜ umero inteiro positivo N e retorne o fatorial ´
quadruplo desse n ´ umero. O fatorial qu ´ adruplo de um n ´ umero N ´ e dado por: (2n)!/n!
*/

#include <stdio.h>

double fatorialQuadruplo(int n);

int main() {
    int n;
    scanf("%d", &n);

    printf("Fatorial quádruplo de %d: %lf", n, fatorialQuadruplo(n));

    return 0;
}

double fatorialQuadruplo(int n) {
    if (n == 1) return 2.0;
    return 2 * (2 * n - 1.0) * fatorialQuadruplo(n - 1);
}