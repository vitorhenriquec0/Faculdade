/* 4. Crie um tipo registro chamado Cadastro que tenha os campos Nome (Alfanumérico), Ender (Endereco),
Dnasc (Data), Telefone (Alfanumérico). No mesmo programa, crie os tipos Data e Endereco. Crie um
vetor Contato do tipo Cadastro com 10 elementos. Faça um programa que leia todos os elementos de
Contato e em seguida os imprima. */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[25];
    char rua[20];
    char bairro[15];
    int numero;
    int cep;
    char cidade[15];
    char estado[15];
    char data[10];
    char telefone[10];
} Cadastro;

int main() {
    
    Cadastro Contato[10];
    
    for (int i = 0; i < 10; i++) {
        printf("Digite o nome do cadastro %d:", i + 1);
        scanf("%[^\n]", Contato[i].nome);
        
        printf("Digite a rua do cadastro %d:", i + 1);
        scanf(" %[^\n]", Contato[i].rua);
        printf("Digite o bairro do cadastro %d:", i + 1);
        scanf(" %[^\n]", Contato[i].bairro);
        printf("Digite o numero na rua do cadastro %d:", i + 1);
        scanf(" %d", &Contato[i].numero);
        printf("Digite o CEP do cadastro %d:", i + 1);
        scanf(" %d", &Contato[i].cep);
        printf("Digite a cidade do cadastro %d:", i + 1);
        scanf(" %[^\n]", Contato[i].cidade);
        printf("Digite o estado do cadastro %d:", i + 1);
        scanf(" %[^\n]", Contato[i].estado);
        
        printf("Digite a data de nascimento: ");
        scanf("%[\n]", Contato[i].data);
        
        printf("Digite o telefone do cadastro %d", i + 1);
        scanf("%[^\n]", Contato[i].telefone);
    }
    
    for (int i = 0; i < 10; i++) {
        printf("\n_____ CADASTRO %d _____\n", i + 1);
        printf("\nNome: %s", Contato[i].nome);
        printf("\nData de Nacimento: %s", Contato[i].data);
        printf("\nTelefone: %s", Contato[i].telefone);
        printf("\n_____ ENDEREÇO _____\n");
        printf("\nRua: %s, Número: %d, Bairro: %s", Contato[i].rua, Contato[i].numero, Contato[i].bairro);
        printf("\nCidade: %s, Estado: %s, CEP: %d", Contato[i].cidade, Contato[i].estado, Contato[i].cep);
    }
    
    return 0;
}