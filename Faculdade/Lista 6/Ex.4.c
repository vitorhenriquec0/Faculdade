#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int matA[4][4];
    int maior = matA[0][0];
    int linha_maior, coluna_maior;
    
    srand (time(NULL));
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matA[i][j] = rand() % 100;
        }
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (matA[i][j] > maior) {
                maior = matA[i][j];
                linha_maior = i;
                coluna_maior = j;
            }
        }
    }
    
    printf("Linha maior: %d\n", linha_maior + 1);
    printf("Coluna maior: %d\n", coluna_maior + 1);
    
    return 0;
        
    }