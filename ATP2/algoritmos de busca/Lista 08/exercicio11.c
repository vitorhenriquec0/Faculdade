/*
Implemente uma aplicação que receba um vetor A ∈ RN com N elementos reais, e que
imprima na saída padrão da aplicação o subconjunto {a,b} ⊆ A, tal que a soma a+b seja
a mais próxima de 0.
*/

#include <stdio.h>
#include <math.h>

void EncontrarSoma(float v[], int n);
void ShellSort(float v[], int n);

int main() {

    float A[] = {1.5, -10.2, 85.0, -80.0, 8.0, 30.0}; 
    int n = 6;
    
    EncontrarSoma(A, n);
    
    return 0;
}

void EncontrarSoma(float v[], int n) {

    if (n < 2) return;

    ShellSort(v, n);

    int L = 0;
    int R = n - 1;

    float melhorA = v[L];
    float melhorB = v[R];
    float menorSoma = fabs(v[L] + v[R]);

    while (L < R) {
        float somaAtual = v[L] + v[R];

        if (fabs(somaAtual) < menorSoma) {
            menorSoma = fabs(somaAtual);
            melhorA = v[L];
            melhorB = v[R];
        }

        if (fabs(somaAtual) == 0) {
            melhorA = v[L];
            melhorB = v[R];
            break;
        }

        if (somaAtual < 0) {
            L++;
        } else {
            R--;
        }
    }

    printf("Par mais proximo de 0: {%.2f, %.2f}\n", melhorA, melhorB);
    printf("Soma: %.2f\n", melhorA + melhorB);
}

void ShellSort(float v[], int n) {
    int gap = 1;
    while (gap < n) gap = gap * 3 + 1;

    while (gap > 1) {
        gap /= 3;

        for (int i = gap; i < n; i++) {
            float temp = v[i];
            int j;
            for (j = i; j >= gap && v[j-gap] > temp; j -= gap) {
                v[j] = v[j-gap];
            }
            v[j] = temp;
        }
    }
}