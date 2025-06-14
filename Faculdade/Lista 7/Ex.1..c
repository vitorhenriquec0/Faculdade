/* 1. Faça um programa em Linguagem C para criar uma estrutura composta pelos campos: notaprova,
notatrabalho, média e nome. O programa deve permitir a leitura do nome e notas de um aluno. Em
seguida, o programa deve calcular a média e armazenar no campo correspondente. Imprimir os dados. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float notaProva;
    float notaTrabalho;
    float media;
    char nome[20];
} aluno;


int main() {
    
    aluno aluno1;
    
    printf("Digite a nota da prova:\n");
    scanf("%f", &aluno1.notaProva);
    printf("Digite a nota do trabalho:\n");
    scanf("%f", &aluno1.notaTrabalho);
    printf("Digite o nome:\n");
    scanf(" %[^\n]", aluno1.nome);
    
    aluno1.media = ((aluno1.notaProva + aluno1.notaTrabalho) / 2); 
    
    printf("\nNota da prova: %.2f", aluno1.notaProva);
    printf("\nNota do trabalho: %.2f", aluno1.notaTrabalho);
    printf("\nMédia do aluno: %.2f", aluno1.media);
    printf("\nNome: %s", aluno1.nome);
    
    return 0;

}

