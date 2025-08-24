/*
Crie uma função que receba dois vetores u, v ∈ R
e um número inteiro positivo n, e que retorne a
distância euclidiana entre u e v.
*/

#include <stdio.h>
#include <math.h>

double distancia(double vetorA[], double vetorB[], int dimensao);

int main() {

    int dimensao;

    printf("Digite qual a dimensao desejada: (ex.: 3 (R x R x R))\n");
    scanf("%d", &dimensao);

    double vetorU[dimensao];
    double vetorV[dimensao];

    printf("Digite os %d valores do vetor U\n", dimensao);
    for(int i = 0; i < dimensao; i++) {
        scanf("%lf", &vetorU[i]);
    }

    printf("Digite os %d valores do vetor V\n", dimensao);
    for(int i = 0; i < dimensao; i++) {
        scanf("%lf", &vetorV[i]);
    }

    printf("%.2lf", distancia(vetorU, vetorV, dimensao));

    return 0;
}

double distancia(double vetorA[], double vetorB[], int dimensao) {
    double calculo = 0;
    for (int i = 0; i < dimensao; i++) {
        calculo += pow(vetorA[i] - vetorB[i], 2);
    }
    return sqrt(calculo);
}