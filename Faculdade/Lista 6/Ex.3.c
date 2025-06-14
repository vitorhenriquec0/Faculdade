#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int matA[4][4];
    int linha, coluna;
    float valor;
    int soma_i = 0, soma_j = 0;
    
    srand (time(NULL));
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matA[i][j] = rand() % 10;
        }
    }
    
    printf("Matriz original: \n");
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }
    
    printf("Digite a linha i e coluna j para multiplicar: (de 0 a 3)\n");
    scanf("%d%d", &linha, &coluna);
    
    printf("\nMatriz de i e j multiplicados:\n");
    
    for (int j = 0; j < 4; j++)
    {
        soma_i += matA[linha][j];
    }
    
    for (int i = 0; i < 4; i++)
    {
        soma_j += matA[i][coluna];
    }
    
    valor = soma_i * soma_j;
    
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%2.f ", valor);
        }
        printf("\n");
    }
    
    return 0;
        
    }