/* 4. Escreva um programa em linguagem C para que usuário forneça cinco valores inteiros. O
programa deve permitir entradas de valores maiores que 0. Os primeiros cinco valores devem
ser armazenados em um vetor A e os demais em um vetor B. Em seguida, o programa deve
efetuar a multiplicação entre os valores disponíveis em A e B, armazenando o resultado em um
terceiro vetor C. As posições devem ser multiplicadas de maneira invertida, ou seja, a primeira
posição do vetor A deve ser multiplicada pela última posição do vetor B. O resultado deve ser
armazenado na última posição do vetor C. Esse processo deve ser realizado por meio de
estruturas de repetições. */

#include <stdio.h>

#define n 5

int main () {
    
    int vetA[n], vetB[n], vetC[n];
    
    printf("Digite os 5 valores do vetor A:");
    for (int i = 0; i < n; i++) {
        do {
            printf("A[%d]: ", i);
            scanf("%d", &vetA[i]);
            if (vetA[i] <= 0) {
                printf("Valor inválido. Tente novamente.\n");
            }
        } while (vetA[i] <= 0);
    }
    
    printf("Digite os 5 valores do vetor B:");
    for (int i = 0; i < n; i++) {
        do {
            printf("B[%d]: ", i);
            scanf("%d", &vetB[i]);
            if (vetB[i] <= 0) {
                printf("Valor inválido. Tente novamente.\n");
            }
        } while (vetB[i] <= 0);
    }
    
    
    for (int i = 0; i < n; i++) {
        vetC[n - 1 - i] = vetA[i] * vetB[n - 1 - i];
    }
    
    printf("\nVetor C:\n");
    for (int i = 0; i < n; i++) {
        printf("C[%d]: %d ", i, vetC[i]);
    }
    
    return 0;
}
