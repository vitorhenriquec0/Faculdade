#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int matA[5][5];
    int x;
    int linha, coluna;
    int found = 0;
    
    srand (time(NULL));
    
    printf("Digite um valor qualquer de 0 à 99: \n");
    scanf("%d", &x);
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matA[i][j] = rand() % 100;
        }
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%2d ", matA[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < 5 && !found; i++)
    {
        for (int j = 0; j < 5 && !found; j++)
        {
            if (matA[i][j] == x) {
                linha = i;
                coluna = j;
                found = 1;
            }
        }
    }
    
    if (found) {
        printf("Linha: %d\n", linha + 1);
        printf("Coluna: %d\n", coluna + 1);
    }
    else {
        printf("Não encontrado!");
    }
    
    return 0;
        
}