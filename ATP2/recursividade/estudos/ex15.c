/*
Escreva uma func¸ao recursiva que exibe todos os elementos em um array de inteiros, ˜
separados por espac¸o.
*/

#include <stdio.h>

void imprimirElementos(int vetor[], int n, int inicio);

int main() {
    int vetor[] = {1, 6, 78, 4, 35, 87};
    int n = sizeof(vetor) / sizeof(vetor[0]);

    imprimirElementos(vetor, n, 0);

    return 0;
}

void imprimirElementos(int vetor[], int n, int inicio) {
    if (inicio >= n) return;
    printf("%d ", vetor[inicio]);
    imprimirElementos(vetor, n, inicio + 1);
}

