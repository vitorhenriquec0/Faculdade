/*
Crie um programa que receba um número inteiro N e que aloque memória dinami-
camente para dois vetores ⃗u e ⃗v de tamanho N com seus elementos preenchidos pelo

usuário por meio da entrada padrão. A seguir, realize os seguintes itens:
a) Imprima o resultado da soma desses vetores: u +v.
b) Imprima o resultado da subtração desses vetores: u − v.
c) Imprima o resultado do produto interno/ponto desses vetores: u · v.
d) Imprima o ângulo θ = ang(u, v) entre esses vetores
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M_PI 3.14159265358979323846

int main() {

    int n;

    scanf("%d", &n);

    int *u, *v;

    u = malloc(n * sizeof(int));
    v = malloc(n * sizeof(int));

    if (u == NULL || v == NULL) {
        printf("Erro: Falha ao alocar memoria.\n");
        return 1; // Retorna 1 para indicar um erro
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", (u + i)); // ou &u[i]
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", (v + i)); // ou &v[i]
    }

    // a) Soma dos vetores

    printf("\nVetor da soma: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(u + i) + *(v + i));
    }

    // b) Subtração dos vetores

    printf("\n\nVetor da subtracao: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", *(u + i) - *(v + i));
    }

    // c) Produto interno dos vetores

    printf("\n\nProduto interno: ");
    int produto = 0;
    for (int i = 0; i < n; i++) {
        produto += *(u + i) * *(v + i);
    }
    printf("%d", produto);

    // d) Angulo entre os vetores

    printf("\n\nAngulo entre os vetores: ");
    int somaU = 0;
    int somaV = 0;
    for (int i = 0; i < n; i++) {
        somaU += pow(*(u + i), 2);
        somaV += pow(*(v + i), 2);
    }

    double normaU = sqrt(somaU);
    double normaV = sqrt(somaV);

    double cosseno_theta = (double)produto / (normaU * normaV);
    double angulo_rad = acos(cosseno_theta);
    double angulo_graus = angulo_rad * (180.0 / M_PI);

    printf("%.2f graus\n", angulo_graus);

    free(u);
    free(v);

    return 0;
}