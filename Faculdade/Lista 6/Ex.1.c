#include <stdio.h>
#define n 4

int main()
{
    int matA[n][n];
    int soma = 0;
    
    printf("Digite %d números:", n*n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matA[i][j]);
        }
    }
    
    printf("\nOs números maiores que 10 são: ");
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matA[i][j] > 10) {
                printf("%d, ", matA[i][j]);
                soma++;
            }
        }
    }
    
    printf("\nO total de números maiores que 10 é: %d", soma);
    
    return 0;
}
