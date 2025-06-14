#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    float mat[3][6];
    float colunas_impares = 0;
    float soma_col_2_4 = 0, soma_col_1_2 = 0;
    
    srand(time(NULL));
    
    printf("\nMatriz original:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            mat[i][j] = rand() % 20;
            printf("%10.2f ", mat[i][j]);
        }
        printf("\n");
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j % 2 != 0)
            {
                colunas_impares += mat[i][j];
            }
        }
    }
    printf("\na) Soma de todos valores em colunas ímpares: %.2f\n", colunas_impares);
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j == 1 || j == 3){ // Coluna 2 e 4
                soma_col_2_4 += mat[i][j];
            }
        }
    }
    printf("\nb) Media aritmetica das colunas 2 e 4: %.2f\n", soma_col_2_4  / 6);
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j == 0 || j == 1)
            {
                soma_col_1_2 += mat[i][j];
            }
        }
    }
    printf("\nc) Soma dos elementos da coluna 1 e 2: %.2f\n", soma_col_1_2);
    
    printf("\nd) Matriz modificada:\n\n");
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (j = 5)
            {
                mat[i][j] = soma_col_1_2;
            }
        }
    }
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            printf("%10.2f ", mat[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
    
}
