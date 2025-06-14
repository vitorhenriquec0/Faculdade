#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 3 

int main ()
{
    int matA[n][n], matB[n][n];
    int matR[n][n] = {0};
    int aux;
    
    srand (time(NULL));
    
    printf("Matriz A:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matA[i][j] = rand() % 9;
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz B:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matB[i][j] = rand() % 9;
            printf("%d ", matB[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz R (multiplicação de A e B):\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            aux = 0;
            for (int k = 0; k < 3; k++)
            {
                aux = aux + matA[i][k] * matB[k][j];
            }
            matR[i][j] = aux;
            printf("%d ", matR[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}