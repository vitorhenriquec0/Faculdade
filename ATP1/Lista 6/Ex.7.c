#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 4

int main ()
{
    int matA[n][n];
    
    srand (time(NULL));
    
    printf("Matriz A:\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matA[i][j] = 1 + rand() % 20;
            printf("%2d ", matA[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz modificada:\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > i) {
                matA[i][j] = 0;
            }
            printf("%2d ", matA[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}