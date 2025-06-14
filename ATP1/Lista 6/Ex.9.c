#include <stdio.h>

int main()
{
    char mat[10][10];
    char vet[10];
    int resultado[5] = {0};
    
    printf("Digite as 10 respostas dos 5 alunos:\n");
    
    for (int i =0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            scanf(" %c", &mat[i][j]);
        }
        printf("\n");
    }
    
    printf("Digite o gabarito oficial:\n");
    
    for (int i = 0; i < 10; i++){
        scanf(" %c", &vet[i]);
    }
    
    for (int i =0; i < 5; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (mat[i][j] == vet[j]) {
                resultado[i] += 1;
            }
        }
    }
    
    for (int i = 0; i < 5; i++) {
        printf("\nAluno %d: %d acertos", i + 1, resultado[i]);
    }
    
    return 0;
}