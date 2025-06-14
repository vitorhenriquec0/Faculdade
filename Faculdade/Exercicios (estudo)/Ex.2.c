#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int matA[3][4];
    int soma_linhas[3] = {0};
    int aux;
    
    srand(time(NULL));
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matA[i][j] = rand() % 100;
            printf("%2d ", matA[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < 3; i++)
    {
        aux = 0;
        for (int j = 0; j < 4; j++)
        {
            aux += matA[i][j];
            soma_linhas[i] = aux;
        }
    }
    
    printf("\n");
    
    for (int i = 0; i < 3; i++)
    {
        printf("Linha %d: %d\n", i + 1, soma_linhas[i]);
    }
    
    return 0;
}
