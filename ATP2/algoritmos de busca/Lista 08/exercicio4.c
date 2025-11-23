/*
Construa um programa que receba da entrada padrão da aplicação um vetor A ∈ RN
contendo N elementos. Em seguida, imprima na saída padrão da aplicação a tupla de ele
mentos a1,a2 ∈ A que obtém a maior soma.
Note: O algoritmo deve ter tempo de complexidade O(n), ou seja, não poderá usar força bruta.
*/

#include <stdio.h>

void tupla(float v[], int n);

int main() {

    float v[5] = {5.1, 78.3, 9.3, 2.3, 6.2};
    int n = 5;

    tupla(v, n);

    return 0;

}

void tupla(float v[], int n) {
    if (n < 2) {
        printf("\nO vetor deve ter pelo menos dois elementos.\n");
        return;
    }

    float maior, segundoMaior;

    if (v[0] > v[1]) {
        maior = v[0];
        segundoMaior = v[1];
    } else {
        maior = v[1];
        segundoMaior = v[0];
    }

    for (int i = 2; i < n; i++) {
        if (v[i] > maior) {
            segundoMaior = maior;
            maior = v[i];
        } else if (v[i] > segundoMaior) {
            segundoMaior = v[i];
        }
    }

    printf("Tupla com maior soma: (%.1f, %.1f)\n", maior, segundoMaior);
    printf("Soma: %.1f\n", maior + segundoMaior);
}