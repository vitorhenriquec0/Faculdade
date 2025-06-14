/* 6. Construir um programa em linguagem C para controlar o estoque de um produto. Especificamente, o
programa deve usar um registro composto por um campo (valor numérico) que representa baixas do
produto por dia da semana. Assim, um vetor com seis posições indicará que cada uma define um dia útil
da semana (incluindo o sábado). O programa deve permitir leitura e escrita dos dados. O modelo é dado a
seguir: */

#include <stdio.h>
#include <stdlib.h>

#define diasUteis 6

typedef struct {
    char nomeProduto[20];
    int codigo;
    float valor;
    int baixa[diasUteis];
} cadastro;

int main() {
    
    cadastro produto;
    
    printf("Digite o nome do produto:\n");
    scanf(" %[^\n]", produto.nomeProduto);
    printf("Digite o codigo do produto:\n");
    scanf("%d", &produto.codigo);
    printf("Digite o valor do produto:\n");
    scanf("%f", &produto.valor);
    
    
    printf("Digite as baixas do produto durante os dias uteis da semana (seg-sab):\n");
    for (int i = 0; i < diasUteis; i++) {
        printf("%do dia: ", i +1);
        scanf("%d", &produto.baixa[i]);
    }
    
    printf("\n----- PRODUTO -----\n");
    
    printf("\nNome: %s\n", produto.nomeProduto);
    printf("Código: %d\n", produto.codigo);
    printf("Valor: %.2f\n", produto.valor);
    printf("                   1   2   3   4   5   6\n");
    printf("Baixa (seg à sab): ");
    for (int i = 0; i < diasUteis; i++) {
        printf("%d, ", produto.baixa[i]);
    }
    
    return 0;
}