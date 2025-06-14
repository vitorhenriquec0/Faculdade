/* 20. Seja A e B dois vetores contendo 10 elementos inteiros. Fazer um programa para:
a. ler A e B.
b. Calcular a soma dos elementos de A.
c. Calcular a soma dos elementos de B.
d. Obter o vetor C, que é a soma dos vetores A e B.
e. Obter o vetor D, subtraindo B de A. */

#include <stdio.h>

#define n 10

int main() {
    int vetA[n], vetB[n], vetC[n], vetD[n];
    int somaA = 0, somaB = 0;
    
    printf("\na) Digite os 10 valores de A e os 10 valores de B: \n");
    for (int i = 0; i < n * 2; i++) {
        if (i < 10) {
            printf("VetA [%d]: ", i);
            scanf("%d", &vetA[i]);
        }
        else {
            printf("VetB [%d]: ", i - 10);
            scanf("%d", &vetB[i - 10]);
        }
    }
    
    printf("\n\nb) Soma dos elementos do vetor A: ");
    for (int i = 0; i < n; i++) {
        somaA += vetA[i];
    }
    printf("%d.", somaA);
    
    printf("\n\nc) Soma dos elementos do vetor B: ");
    for (int i = 0; i < n; i++) {
        somaB += vetB[i];
    }
    printf("%d.", somaB);
    
    printf("\n\nd) Soma dos vetores A e B (Vetor C): ");
    for (int i = 0; i < n; i++) {
        vetC[i] = vetA[i] + vetB[i];
        printf("\nVetC [%d]: %d", i, vetC[i]);
    }
    
    printf("\n\ne) Subtração do vetor B em A: ");
    for (int i = 0; i < n; i++) {
        vetD[i] = vetA[i] - vetB[i];
        printf("\nVetD [%d]: %d", i, vetD[i]);
    }
    
    return 0;
}
