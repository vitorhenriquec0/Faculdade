/*
Construa uma aplicação que receba um vetor A ∈ RN com N elementos, e imprima na
saída padrão da aplicação o elemento mais frequente. Caso não hou ver um elemento mais
frequente, imprima na saída padrão o valor −1.
*/

#include <stdio.h>

void ShellSort(float v[], int n);
void Frequencia(float v[], int n);

int main() {
    float v1[] = {10.0, 20.0, 5.0, 20.0, 10.0, 20.0, 1.0}; 
    int n1 = 7;

    float v2[] = {10.0, 20.0, 5.0, 20.0, 10.0, 1.0}; 
    int n2 = 6;

    float v3[] = {1.0, 2.0, 3.0};
    int n3 = 3;

    printf("\nTeste 1:\n");
    Frequencia(v1, n1);

    printf("\nTeste 2:\n");
    Frequencia(v2, n2);

    printf("\nTeste 3:\n");
    Frequencia(v3, n3);

    return 0;
}

void Frequencia(float v[], int n) {
    ShellSort(v, n);

    float campeao = -1.0;
    int freqMax = 0;
    int countAtual = 1;
    int empate = 0;

    for (int i = 1; i <= n; i++) {
        if (i < n && v[i-1] == v[i]) {
            countAtual++;
        } else {
            if (countAtual > freqMax) {
                freqMax = countAtual;
                campeao = v[i-1];
                empate = 0;
            } else if (countAtual == freqMax) {
                empate = 1;
            }
            countAtual = 1;
        }
    }

    if (empate || freqMax == 1) {
        printf("-1\n");
    } else {
        printf("Elemento mais frequente: %.1f (%d vezes)", campeao, freqMax);
    }
}

void ShellSort(float v[], int n) {
    int gap = 1;
    while (gap < n) gap = gap * 3 + 1;
    
    while (gap > 1) {
        gap /= 3;

        for (int i = gap; i < n; i++) {
            float temp = v[i];
            int j;
            for (j = i; j >= gap && v[j - gap] > temp; j-= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}