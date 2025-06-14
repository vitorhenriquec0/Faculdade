/* 12. Dado um vetor VIN de 10 elementos inteiros, criar um vetor VAI de 30 elementos, sendo que
VAI[0], VAI[1] e VAI[2] recebe o valor de VIN[0] e assim por diante. Escrever um programa
que leia VIN e imprima VAI. */

#include <stdio.h>

#define n 10

int main () {
    
    int VIN[n], VAI[n * 3];
    
    printf("Digite os 10 valores do vetor VIN\n");
    for (int i = 0; i < n; i++) {
        printf("Elemento [%d]: ", i);
        scanf("%d", &VIN[i]);
    }
    
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            VAI[(i * 3) + j] = VIN[i];
        }
        
    }
    
    printf("Vetor VAI: ");
    for (int i = 0; i < n * 3; i++) {
        printf("%d ", VAI[i]);
    }
    
    return 0;
}
