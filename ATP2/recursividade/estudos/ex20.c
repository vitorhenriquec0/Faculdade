/*
Fac¸a uma func¸ao recursiva que receba um n ˜ umero inteiro positivo impar N e retorne ´
o fatorial duplo desse numero. O fatorial duplo ´ e definido como o produto de todos os ´
numeros naturais ´ ´ımpares de 1 ate algum n ´ umero natural ´ ´ımpar N
*/

#include <stdio.h>

double duploFatorial(int n);

int main() {
    int n;
    scanf("%d", &n);

    printf("%lf", duploFatorial(n));

    return 0;
}

double duploFatorial(int n) {
    if (n == 1) return 1;
    return n * duploFatorial(n - 2);
}