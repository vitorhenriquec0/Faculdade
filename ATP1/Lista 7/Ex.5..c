/* 5. Faça um programa que, utilizando registros, leia o nome e data de nascimento (dia mês ano) de n pessoas
(n = 40), calcule e mostre a idade de cada pessoa e o nome da pessoa mais velha. Suponha que não temos
duas (ou mais) pessoas com a mesma idade. */

#include <stdio.h>
#include <stdlib.h>

#define n 40

typedef struct {
    char nome[25];
    int dia;
    int mes;
    int ano;
    int idade;
} registro;

int main() {
    
    registro cadastro[n];
    int idade_maior = 0;
    int indice_maior = 0;
    
    for (int i = 0; i < n; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        scanf(" %[^\n]", cadastro[i].nome);
        printf("Digite a data de nascimento da pessoa %d: ", i + 1);
        scanf("%d%d%d", &cadastro[i].dia, &cadastro[i].mes, &cadastro[i].ano);
        cadastro[i].idade = 2025 - cadastro[i].ano;
    }
    
    for (int i = 0; i < n; i++) {
        if (cadastro[i].idade > idade_maior) {
            idade_maior = cadastro[i].idade;
            indice_maior = i;
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("\n%do Nome: %s", i + 1, cadastro[i].nome);
        printf("\n    Idade: %d\n", cadastro[i].idade);
    }
    
    printf("\nA pessoa mais velha é: %s", cadastro[indice_maior].nome);
    
}