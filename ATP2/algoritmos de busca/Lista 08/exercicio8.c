/*
Implemente um programa que receba uma sequência A ∈ ZN com N números natu
rais, de modo que, a diferença entre quaisquer elementos consecutivos é constante, isto
 é, xi − xi−1 = c, para algum c ∈ N. Em seguida, imprima na saída padrão da aplicação o
 termo faltante nessa sequência.
*/

#include <stdio.h>

int Faltante(int v[], int n);

int main() {
    int v[] = {2, 4, 6, 10, 12}; 
    int n = 5;

    int faltante = Faltante(v, n);
    
    printf("O termo faltante eh: %d\n", faltante);

    return 0;
}

int Faltante(int v[], int n) {
    int c = (v[n-1] - v[0]) / n;

    if (c == 0) return v[0];

    int e = 0;
    int d = n - 1;

    while (e < d) {
        int m = (e + d) / 2;

        int valorEsperado = v[0] + (c * m);

        if (v[m] == valorEsperado) {
            e = m + 1;
        } else {
            d = m;
        }
    }

    return v[0] + (e * c);
}