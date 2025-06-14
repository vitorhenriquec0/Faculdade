/* 8. Construir um programa em linguagem C para controlar o saldo bancário de 20 clientes. Alguns dados
importantes são: número da conta; data de abertura da conta; cliente; saldo; e, limite especial.
Complementar o controle das informações com outros dados comumente vinculados aos dados de um
cliente/conta. Os dados pessoais de um cliente (nome, sobrenome, sexo e outros) devem ser armazenados
em um registro cliente. Os dados de cada conta devem ser armazenados em um registro conta. Cada conta
está associada a um cliente. O programa deve permitir ler todos dados. Calcular e imprimir o saldo médio
das mulheres, o saldo médio dos homens, o maior e o menor saldo entre homens e mulheres, cliente mais
antigo, cliente com o maior limite especial, clientes com saldos negativos e listar os clientes por saldo
bancário (ordem crescente). */

#include <stdio.h>
#include <stdlib.h>

#define n 20

typedef struct {
    char nome[20];
    char sobrenome[10];
    char sexo;
} registroCliente;

typedef struct {
    int numeroDaConta;
    int dia, mes, ano;
    registroCliente cliente;
    float saldo;
    float limiteEspecial;
} registroBanco;

int main() {
    
    registroBanco clienteBanco[n];
    
    registroBanco clientesNegativos[n];
    int qtdNegativos = 0;

    
    float somaSaldoHomem = 0, somaSaldoMulher = 0;
    float totalHomem = 0, totalMulher = 0;
    
    float maiorSaldoHomem = 0, maiorSaldoMulher = 0;
    float menorSaldoHomem = 99999, menorSaldoMulher = 99999;
    
    float maiorLimiteEspecial = 0;
    int maiorIndiceLimiteEspecial;
    
    int maisVelho = 2025;
    
    for (int i = 0; i < n; i++){
        printf("Digite o nome do %do cliente: ", i + 1);
        scanf(" %[^\n]", clienteBanco[i].cliente.nome);
        printf("\nDigite o sobrenome do %do cliente: ", i + 1);
        scanf(" %[^\n]", clienteBanco[i].cliente.sobrenome);
        printf("\nDigite o sexo do %do cliente (H ou M): ", i + 1);
        scanf(" %c", &clienteBanco[i].cliente.sexo);
        printf("\nDigite o número da conta do %do cliente: ", i + 1);
        scanf("%d", &clienteBanco[i].numeroDaConta);
        printf("\nDigite o dia, mes e ano de nascimento do %do cliente (00/00/0000): ", i + 1);
        scanf("%d%d%d", &clienteBanco[i].dia, &clienteBanco[i].mes, &clienteBanco[i].ano);
        printf("\nDigite o saldo da conta do %do cliente: ", i + 1);
        scanf("%f", &clienteBanco[i].saldo);
        printf("\nDigite o limite especial da conta do %do cliente: ", i + 1);
        scanf("%f", &clienteBanco[i].limiteEspecial);
        
        if (clienteBanco[i].saldo < 0) {
            clientesNegativos[qtdNegativos++] = clienteBanco[i];
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (clienteBanco[i].cliente.sexo == 'H' || clienteBanco[i].cliente.sexo == 'h') {
            somaSaldoHomem += clienteBanco[i].saldo;
            totalHomem++;
            
            if (clienteBanco[i].saldo > maiorSaldoHomem) {
                maiorSaldoHomem = clienteBanco[i].saldo;
            }
            if (clienteBanco[i].saldo < menorSaldoHomem) {
                menorSaldoHomem = clienteBanco[i].saldo;
            }
        }
        else {
            somaSaldoMulher += clienteBanco[i].saldo;
            totalMulher++;
            
            if (clienteBanco[i].saldo > maiorSaldoMulher) {
                maiorSaldoMulher = clienteBanco[i].saldo;
            }
            if (clienteBanco[i].saldo < menorSaldoMulher) {
                menorSaldoMulher = clienteBanco[i].saldo;
            }
        }
        
        if (clienteBanco[i].limiteEspecial > maiorLimiteEspecial) {
            maiorLimiteEspecial = clienteBanco[i].limiteEspecial;
            maiorIndiceLimiteEspecial = i;
        }
    }
    
    for (int i =  0; i < n; i++) {
        if (clienteBanco[i].ano < maisVelho) {
            maisVelho = clienteBanco[i].ano;
        }
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (clienteBanco[i].saldo > clienteBanco[j].saldo) {
                // Troca os registros de posição
                registroBanco temp = clienteBanco[i];
                clienteBanco[i] = clienteBanco[j];
                clienteBanco[j] = temp;
        }
    }
}
    
    printf("\nSaldo médio dos homens: %.2f\n", somaSaldoHomem / totalHomem);
    printf("Saldo médio das mulheres: %.2f\n", somaSaldoMulher / totalMulher);
    printf("Maior saldo entre homens: %.2f\n", maiorSaldoHomem);
    printf("Menor saldo entre homens: %.2f\n", menorSaldoHomem);
    printf("Maior saldo entre mulheres: %.2f\n", maiorSaldoMulher);
    printf("Menor saldo entre mulheres: %.2f\n", menorSaldoMulher);
    printf("Cliente com maior limite especial: %s\n", clienteBanco[maiorIndiceLimiteEspecial].cliente.nome); 
    
    printf("\nClientes com saldo negativo:\n");
    for (int i = 0; i < qtdNegativos; i++) {
        printf("%s %s - Saldo: %.2f\n", clientesNegativos[i].cliente.nome, clientesNegativos[i].cliente.sobrenome, clientesNegativos[i].saldo);
    }
    
    printf("\nClientes ordenados pelo saludo:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s - Saldo: %.2f\n", clienteBanco[i].cliente.nome, clienteBanco[i].cliente.sobrenome, clienteBanco[i].saldo);
    }
    
    return 0;
}
