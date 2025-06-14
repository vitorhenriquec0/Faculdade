#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 4

int main ()
{
    int matA[n][n], matB[n][n], matC[n][n];
    
    srand (time(NULL));
    
    printf("Matriz A:\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matA[i][j] = rand() % 101;
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz B:\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matB[i][j] = rand() % 101;
            printf("%d ", matB[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz C:\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (matA[i][j] > matB[i][j]) {
                matC[i][j] = matA[i][j];
            }
            else {
                matC[i][j] = matB[i][j];
            }
            printf("%d ", matC[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}