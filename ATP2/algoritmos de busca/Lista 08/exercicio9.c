/*
Escreva um algoritmo que encontre a raiz quadrada √x de um 
número quadrado perfeito x ∈ N, usando para isso a ideia
do algoritmo de busca binária.
*/

#include <stdio.h>

int RaizQuadradaBinaria(int x);

int main() {
    int x = 9;

    int resultado = RaizQuadradaBinaria(x);

    printf("%d", resultado);

    return 0;
}

int RaizQuadradaBinaria(int x) {
    if (x < 0) return -1;
    if (x == 0 || x == 1) return x;

    int e = 0;
    int d = x;
    
    while (e <= d) {
        long long m = (e + d) / 2;

        long long quadrado = m * m;

        if (quadrado == x) {
            return (int)m;
        } else if (quadrado < x) {
            e = m + 1;
        } else {
            d = m - 1;
        }
    }

    return -1; // nao é quadrado perfeito
}