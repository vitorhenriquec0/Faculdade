/* Crie um programa que receba um número inteiro N e que aloque memória dinami-
camente para um vetor de números inteiros. A seguir, imprima na saída padrão da apli-
cação o endereço de memória de cada elemento do vetor. */

#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    int *vet;

    scanf("%d", &N);

    vet = calloc(N, sizeof(int));

    for (int i = 0; i < N; i++) {
        printf("Endereco [%d]: %p\n", i, &vet[i]);
    }

    free(vet);

    return 0;

}