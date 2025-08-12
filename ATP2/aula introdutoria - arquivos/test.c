#include <stdio.h>
#include <stdlib.h>

#define total 3

typedef struct
{   
    float notaProva;
    float notaTrabalho;
    float media;
    char nome[20];
} aluno;

int main()
{

    FILE *arq;

    arq = fopen("text.txt", "w");

    aluno alunos[total];

    if (arq != NULL)
    {
        printf("O arquivo foi gerado com sucesso!");
        fprintf(arq, "Nome\tNota Prova\tNota Trabalho\tMédia\n");

        for (int i = 0; i < total; i++)
        {
            printf("Digite o nome do %do aluno:\n", i + 1);
            scanf(" %[^\n]", alunos[i].nome);
            printf("\nDigite a nota da prova do %do aluno:\n", i + 1);
            scanf("%f", &alunos[i].notaProva);
            printf("Digite a nota do trabalho do %do aluno:\n", i + 1);
            scanf("%f", &alunos[i].notaTrabalho);

            alunos[i].media = ((alunos[i].notaProva + alunos[i].notaTrabalho) / 2);

            fprintf(arq, "%s\t%.2f\t%.2f\t%.2f\n", alunos[i].nome, alunos[i].notaProva, alunos[i].notaTrabalho, alunos[i].media);
        }
        fclose(arq);
    }
    else
    {
        printf("O arquivo não foi gerado.");
    }

    return 0;
}