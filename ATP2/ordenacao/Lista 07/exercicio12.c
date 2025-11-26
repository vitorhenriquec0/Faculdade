/*
Construa um programa que receba um vetor A∈R N e dois números reais m, M∈R, e
 que imprima na saída padrão da aplicação o vetor A′, tal que todos os elementos de A
 menores ou iguais a m venham primeiro, que todos elementos no intervalo [m,M] venham
 em seguida, e que todos os elementos maiores ou iguais a M venham por último.
*/

#include <stdio.h>

void trocar(int v[], int i, int j) {
    int temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void Separar(int v[], int n, int m, int M) {
    int menor = 0;
    int meio = 0;
    int maior = n - 1;

    while (meio <= maior) {

        if (v[meio] < m) {
            trocar(v, meio, menor);
            meio++;
            menor++;
        } else if (v[meio] > M) {
            trocar(v, meio, maior);
            maior--;
        } else {
            meio++;
        }
    }
}

int main() {
    int m, M;

    printf("\nDigite o intervalo [m, M]: ");
    scanf("%d%d", &m, &M);

    int n;
    printf("\nDigite o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];
    printf("\nDigite os %d elementos do vetor: ", n);
    for (int i = 0; i < n; i++) scanf("%d", &vetor[i]);

    printf("Vetor original: ");
    for (int i = 0; i< n; i++) printf("%d ", vetor[i]);

    Separar(vetor, n, m, M);

    printf("\n\nVetor com intervalo[%d, %d]: ", m, M);
    for (int i =0; i < n; i++) printf("%d ", vetor[i]);

    return 0;
}