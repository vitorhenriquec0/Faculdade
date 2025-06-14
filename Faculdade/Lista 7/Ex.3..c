/* 3. Faça um programa em Linguagem C para criar um registro que permita armazenar os dados comumente
contidos em um cheque bancário. O programa deve permitir entrada e saída dos dados. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char emitente[30];
    char beneficiario[30];
    char banco[30];
    float valor;
} cheque;

int main() {
    
    cheque cheque1;
    
    printf("Digite o nome do emitente: ");
    scanf(" %[^\n]", cheque1.emitente);
    printf("Digite o nome do beneficiario: ");
    scanf(" %[^\n]", cheque1.beneficiario);
    printf("\nDigite o nome do banco: ");
    scanf(" %[^\n]", cheque1.banco);
    printf("\nDigite o valor do cheque: ");
    scanf("%f", &cheque1.valor);
    
    printf("------ CHEQUE ------");
    
    printf("\n\nEmitente: %s", cheque1.emitente);
    printf("\nNome: %s", cheque1.beneficiario);
    printf("\nBanco: %s", cheque1.banco);
    printf("\nValor: %.2f", cheque1.valor);
    
    return 0;
}