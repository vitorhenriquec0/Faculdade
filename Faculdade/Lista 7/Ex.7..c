/* Construir um programa em linguagem C para controlar o estoque de um produto. Especificamente, o
programa deve usar um registro composto por um campo (valor numérico) que representa baixas do
produto por dia da semana. Assim, um vetor com seis posições indicará que cada uma define um dia útil
da semana (incluindo o sábado). O programa deve permitir leitura e escrita dos dados. O modelo é dado a
seguir: 

7. Modifique o programa anterior para comportar os dados de 20 produtos.

*/

#include <stdio.h>
#include <stdlib.h>

#define diasUteis 6
#define n 2

typedef struct {
    char nomeProduto[20];
    int codigo;
    float valor;
    int baixa[diasUteis];
} cadastro;

int main() {
    
    cadastro produto[n];
    
    for (int i = 0; i < n; i ++) {
        printf("Digite o nome do produto:\n");
        scanf(" %[^\n]", produto[i].nomeProduto);
        printf("Digite o codigo do produto:\n");
        scanf("%d", &produto[i].codigo);
        printf("Digite o valor do produto:\n");
        scanf("%f", &produto[i].valor);
        printf("Digite as baixas do produto durante os dias uteis da semana (seg-sab):\n");
            for (int j = 0; j < diasUteis; j++) {
            printf("%do dia: ", j +1);
            scanf("%d", &produto[i].baixa[j]);
        }
    }
    
    
    
    
    for (int i = 0; i < n; i++) {
        printf("\n\n----- PRODUTO %d -----\n", i + 1);
    
        printf("\nNome: %s\n", produto[i].nomeProduto);
        printf("Código: %d\n", produto[i].codigo);
        printf("Valor: %.2f\n", produto[i].valor);
        printf("                   1   2   3   4   5   6\n");
        printf("Baixa (seg à sab): ");
            for (int j = 0; j < diasUteis; j++) {
            printf("%d, ", produto[i].baixa[j]);
        }
    }
    
    return 0;
}