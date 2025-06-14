/* 19. Escreva um programa que leia dois vetores A e B com 10 posições. Em seguida, o programa
deve realizar a multiplicação entre os elementos (com o mesmo índice) contidos nos vetores.
O resultado deve ser armazenado em um vetor C. Mostre o vetor resultante. */

#include <stdio.h>

#define n 10

int main() {
    
    int vetA[n], vetB[n], vetC[n];
    
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
    
    printf("\nVetor C:\n\n");
    for (int i = 0; i < n; i++) {
        vetC[i] = vetA[i] * vetB[i];
        printf("%d ", vetC[i]);
    }
    
    return 0;
}
