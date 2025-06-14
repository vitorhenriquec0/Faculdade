/* 30. Escreva um código para ler 4 elementos e armazená-los em uma matriz A[2][2]. Em seguida, o programa
deve calcular e apresentar o determinante de A. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    
    int matA[2][2];
    int prodDet1 = 1, prodDet2 = 1;
    int determinante;
    
    srand(time(NULL));
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            matA[i][j] = rand() % 10;
            printf("%2d ", matA[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            if (i == j) {
                prodDet1 *= matA[i][j];
            }
            else {
                prodDet2 *= matA[i][j];
            }
        }
    }
    
    determinante = prodDet1 - prodDet2;
    printf("Determinante: %d", determinante);
    
    return 0;
    
}
