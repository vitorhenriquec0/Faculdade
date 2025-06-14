#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 5

int main () {
    
    int matA[n][n];
    int pares = 0, impares = 0;
    
    srand(time(NULL));
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matA[i][j] = rand () % 10;
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matA[i][j] % 2 == 0) {
                pares++;
            }
            else {
                impares++;
            }
        }
    }
    
    printf("A matriz possui %d numeros pares.\n", pares);
    printf("A matriz possui %d numeros impares.\n", impares);
}
