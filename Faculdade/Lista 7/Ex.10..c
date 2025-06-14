/* 10. Um provedor de acesso à Internet mantém o seguinte cadastro de clientes: código do cliente, e-mail,
número de horas de acesso, página (S-sim ou N-não). Elaborar um programa em C que calcule e mostre
um relatório contendo o valor a pagar por cada cliente, sabendo-se que as primeiras 20 horas de acesso
custam R$35,00 e cada hora excedente tem o custo de R$2,50. Os clientes que têm páginas devem ter um
acréscimo de R$40,00 a sua conta. O provedor tem um total de 20 clientes. O programa deve exibir um
relatório em que cada registro deve aparecer em uma linha. Além disso, o programa deve exibir o total a
receber. */

#include <stdio.h>
#include <stdlib.h>

#define n 20

typedef struct {
    int codigoCliente;
    char emailCliente[30];
    int horasCliente;
    char paginaCliente;
} registroCliente;

int main() {
    
    registroCliente relatorio[n];
    float total = 0;
    
    for (int i = 0; i < n; i++) {
        printf("Digite o codigo do %do cliente: ", i + 1);
        scanf("%d", &relatorio[i].codigoCliente);
        printf("Digite o email do %do cliente: ", i + 1);
        scanf(" %[^\n]", relatorio[i].emailCliente);
        printf("Digite quantas horas o %do cliente utilizou: ", i + 1);
        scanf("%d", &relatorio[i].horasCliente);
        printf("O cliente possui pagina hospedada? (S/N)");
        scanf(" %c", &relatorio[i].paginaCliente);
    }
    
    for (int i = 0; i < n; i++) {
        
        float valorPagar = 35.00;
        int horasExtra = 0;
        
        if (relatorio[i].horasCliente > 20) {
            horasExtra = relatorio[i].horasCliente - 20;
            valorPagar += horasExtra * 2.5;
        }
        
        if (relatorio[i].paginaCliente == 's' || relatorio[i].paginaCliente == 'S') {
            valorPagar += 40;
        }
        
        printf("\nCliente %d (%s) || Valor a pagar: %.2f\n", relatorio[i].codigoCliente, relatorio[i].emailCliente, valorPagar);
        
        total += valorPagar;
    }
    
    printf("Total a receber: %.2f", total);
    
    return 0;
}
