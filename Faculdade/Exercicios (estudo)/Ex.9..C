/* Defina uma struct Tarefa com os campos: descricao (string, máximo de 100 caracteres), prioridade (inteiro, variando de 1 a 5, onde 5 representa a prioridade mais alta) e status (char, 'P' para pendente, 'C' para concluída). Crie um programa que permita ao usuário cadastrar até 20 tarefas em um vetor de struct Tarefa. Após o cadastro, o programa deve exibir:
Todas as tarefas cadastradas (descrição, prioridade e status).
Apenas as tarefas com prioridade máxima (nível 5) que ainda estão com status 'P' (pendente).
A quantidade total de tarefas que foram marcadas como 'C' (concluídas). */

#include <stdio.h>
#include <stdlib.h>

#define n 3

typedef struct {
    char descricao[100];
    int prioridade;
    char status;
} Tarefa;

int main () {
    
    Tarefa atividades[n];
    
    printf("Digite as atividades:\n");
    for (int i = 0; i < n; i++) {
        printf("Atividade [%d]", i + 1);
        printf("Descrição: ");
        scanf(" %[^\n]", atividades[i].descricao);
        printf("Prioridade (de 1 a 5):");
        scanf("%d", &atividades[i].prioridade);
        printf("Status (P-Pendente | C-Concluida):");
        scanf(" %c", &atividades[i].status);
    }
    
    for (int i = 0; i < n; i++) {
        printf("\n\n--- ATIVIDADE %d ---\n\n", i + 1);
        printf("Descrição: %s\n", atividades[i].descricao);
        printf("Prioridade: %d\n", atividades[i].prioridade);
        printf("Status: %c\n", atividades[i].status);
    }
    
    printf ("\n\n--- ATIVIDADES DE NÍVEL 5 PENDENTES ---\n\n");
    for (int i = 0; i < n; i++) {
        if (atividades[i].prioridade == 5 && (atividades[i].status == 'P' || atividades[i].status == 'p')) {
            printf("Atividade [%d]\n", i + 1);
        }
    }
    
    printf ("\n\n--- ATIVIDADES CONCLUÍDAS ---\n\n");
    for (int i = 0; i < n; i++) {
        if (atividades[i].status == 'C' || atividades[i].status == 'c') {
            printf("Atividade [%d]\n", i + 1);
        }
    }
    
    return 0;
}
