#include <stdio.h>

#define n 4

int main()
{
    int matA[n][n], matB[n][n], matC[n][n];
    
    printf("Digite 32 valores inteiros:\n");
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &matA[i][j]);
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &matB[i][j]);
        }
    }
    
    printf("\nMatriz A:\n");
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%2d, ", matA[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz B:\n");
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%2d, ", matB[i][j]);
        }
        printf("\n");
    }
    
    printf("\nSoma da matriz A e B:\n");
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matC[i][j] = matA[i][j] + matB[i][j];
            printf("%2d ", matC[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}