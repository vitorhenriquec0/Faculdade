/*
Crie um programa que receba uma quantidade arbitrária de números reais não neg-
ativos. O usuário indicará que não inserirá mais entradas uma vez que for inserido um

número negativo. Dessa forma, a partir dos números inseridos pelo usuário, realize os
seguintes itens:
a) Imprima a quantidade de números inseridos pelo usuário.
b) Imprima o maior número inserido.
c) Imprima o menor número inserido.
d) Imprima a soma desses valores.
e) Imprima a média aritmética desses valores.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    float *vetor;
    int j = 0;
    int capacidade = 5;

    vetor = calloc(capacidade, sizeof(float));

    while(1) {
        scanf("%f", (vetor + j));

        if (*(vetor + j) < 0) {
            break;
        }

        j++;

        if (j >= capacidade) {
            capacidade *= 2;
            vetor = realloc(vetor, capacidade * sizeof(float));
        }

    }

    // a) Imprimir a quantidade de numeros inseridos

    printf("\nQuantidade de numeros: %d", j);

    // b) Maior número
    // c) Menor número

    float maior = *vetor;
    float menor = *vetor;
    for (int i = 0; i < j; i++) {
        if (*(vetor + i) > maior) {
            maior = *(vetor + i);
        }
        if (*(vetor + i) < menor) {
            menor = *(vetor + i);
        }
    }

    printf("\n\nMaior numero: %.2f", maior);
    printf("\n\nMenor numero: %.2f", menor);

    // d) Soma dos numeros

    float soma = 0;
    for (int i = 0; i < j; i++) {
        soma += *(vetor + i);
    }

    printf("\n\nSoma dos numeros: %.2f", soma);

    // e) Media aritmetica dos valores

    float media = soma / j;
    printf("\n\nMedia aritmetica dos numeros: %.2f", media);

    free(vetor);

    return 0;
}