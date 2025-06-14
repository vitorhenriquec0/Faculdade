/* 2. Repita o exercício anterior, porém considere que a struct deve permitir o armazenamento dos dados de 10
alunos. */

#include <stdio.h>
#include <stdlib.h>

#define total 10

typedef struct {
    float notaProva;
    float notaTrabalho;
    float media;
    char nome[20];
} aluno;


int main() {
    
    aluno alunos[total];
    
    for (int i = 0; i < total; i++) {

        printf("\nDigite a nota da prova do %do aluno:\n", i + 1);
        scanf("%f", &alunos[i].notaProva);
        printf("Digite a nota do trabalho do %do aluno:\n", i + 1);
        scanf("%f", &alunos[i].notaTrabalho);
        printf("Digite o nome do %do aluno:\n", i + 1);
        scanf(" %[^\n]", alunos[i].nome);
        
        alunos[i].media = ((alunos[i].notaProva + alunos[i].notaTrabalho) / 2); 
    }

    for (int i = 0; i < total; i++) {
        printf("\nNota da prova do %do aluno: %.2f", i + 1, alunos[i].notaProva);
        printf("\nNota do trabalho do %do aluno: %.2f", i + 1, alunos[i].notaTrabalho);
        printf("\nMédia do aluno do %do aluno: %.2f",i + 1, alunos[i].media);
        printf("\nNome do %do aluno: %s",i + 1, alunos[i].nome);
    }
    
    return 0;

}

