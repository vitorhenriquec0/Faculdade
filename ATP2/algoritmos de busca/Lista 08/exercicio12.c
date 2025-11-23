/*
Construa um programa que receba da entrada padrão da aplicação um número natural
positivo n > 0 e imprima na saída padrão da aplicação os números cujo fatorial termina
com uma quantidade de n zeros
*/

#include <stdio.h>

long long ContarZeros(long long num);
void FatorialComNZeros(int n);

int main() {
    int n;
    
    printf("Digite a quantidade de zeros desejada (n): ");
    scanf("%d", &n);

    FatorialComNZeros(n);

    return 0;
}

long long ContarZeros(long long num) {
    long long zeros = 0;

    for (long long i = 5; num / i >= 1; i *= 5) {
        zeros += num / i;
    }

    return zeros;
}

void FatorialComNZeros(int n) {
    long long e = 0;
    long long d = (long long)n * 5; // estimativa segura
    long long choose = -1;

    while (e <= d) {
        long long m = (e + d) / 2;
        long long totalZeros = ContarZeros(m);

        if (totalZeros >= n) {
            choose = m;
            d = m - 1;
        } else {
            e = m + 1;
        }
    }

    if (ContarZeros(choose) == n) {
        printf("Numeros cujo fatorial tem %d zeros:\n", n);
        for (int i = 0; i < 5; i++) {
            printf("%lld ", choose + i);
        }
        printf("\n");
    } else {
        printf("Nenhum numero natural possui fatorial com exatamente %d zeros.\n", n);
    }
}