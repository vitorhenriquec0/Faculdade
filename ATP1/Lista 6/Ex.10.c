#include <stdio.h>

int main()
{
    char alunos[6][10];
    char gabarito[10];
    int matricula[6];
    int notas[10] = {0};
    float maiores = 0;
    
    printf("Digite o gabarito oficial:\n");
    
    for (int i = 0; i < 10; i++)
    {
        scanf(" %c", &gabarito[i]);
    }
    
    printf("Digite a matricula e as respostas de cada aluno:\n");
    
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &matricula[i]);
        for (int j = 0; j < 10; j++)
        {
            scanf(" %c", &alunos[i][j]);
        }
        
    }
    
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (alunos[i][j] == gabarito[j])
            {
                notas[i]++;
            }
        }
    }
    
    for (int i = 0; i < 6; i++)
    {
        printf("\nMatrícula: %d\n", matricula[i]);
        printf("Respostas: ");
        for (int j = 0; j < 10; j++)
        {
            printf("%c, ", alunos[i][j]);
        }
        printf("Nota: %d", notas[i]);
    }
    
    for (int i = 0; i < 6; i++)
    {
        if (notas[i] >= 7)
        {
            maiores++;
        }
    }
    
    printf("\nO percentual de aprovados é: %.2f", (maiores / 6)*100);
    
    return 0;
}