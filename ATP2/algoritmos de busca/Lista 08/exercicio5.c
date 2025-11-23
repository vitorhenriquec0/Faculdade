/*
Implemente um programa que receba da entrada padrão da aplicação um vetor A ∈ RN
e imprima na saída padrão o primeiro elemento pico encontrado. Um elemento xk é dito
pico se os elementos adjacentes xk−1 e xk+1 são menores ou iguais a ele
*/

#include <stdio.h>

int pico(float v[], int n);

int main() {
    float v[] = {1.0, 5.0, 20.0, 10.0, 50.0, 60.0}; 
    int n = 6;

    int indicePico = pico(v, n);

    if (indicePico != -1) {
        printf("Primeiro pico encontrado no indice: %d (Valor: %.1f)\n", indicePico, v[indicePico]);
    } else {
        printf("Nenhum pico encontrado.\n");
    }

    return 0;
}


int pico(float v[], int n) {
    if (n == 1) return 0;

    if (v[0] >= v[1]) return 0;

    for (int i = 1; i < n - 1; i++) {
        if (v[i-1] <= v[i] && v[i+1] <= v[i]) return i;
    }

    if (v[n-1] >= v[n-2]) return n-1;

    return -1; // caso raro, por segurança

}