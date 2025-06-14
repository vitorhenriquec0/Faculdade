/* 23. Escreva um programa em linguagem C para que usuário digite um nome e um sobrenome,
sendo esses armazenados em variáveis nome e sobrenome, respectivamente. As strings têm
tamanhos máximos de 40 caracteres. Em seguida, o programa deve percorrer as strings,
concatenar as entradas e armazenar o resultado em uma string nomeada resultado,
declarada com tamanho 80. Ao final, o programa deverá apresentar o resultado da
concatenação com o total de algarismos existentes. */

#include <stdio.h>

int main() {
    
    char nome[41], sobrenome[41], concatenacao[82];
    int contAlgarismos = 0;
    int contNome = 0;
    int contSobrenome = 0;
    int espaco = 0;
    char c;
    
    printf("Digite o nome: \n");
    scanf(" %[^\n]", nome);
    printf("Digite o sobrenome: \n");
    scanf(" %[^\n]", sobrenome);
    
    while (nome[contNome] != '\0') {
        contNome++;
    }
    
    while (sobrenome[contSobrenome] != '\0') {
        contSobrenome++;
    }
    
    for (int i = 0; i < contNome; i++) {
        concatenacao[espaco] = nome[i];
        espaco++;
    }
    
    concatenacao[espaco] = ' ';
    espaco++;
    
    for (int i = 0; i < contSobrenome; i++) {
        concatenacao[espaco] = sobrenome[i];
        espaco++;
    }
    
    concatenacao[espaco] = '\0';
    
    printf("Nome e sobrenome: %s", concatenacao);
    for (int i = 0; concatenacao[i] != '\0'; i++) {
        c = concatenacao[i];
        if (c >= '0' && c <= '9') {
            contAlgarismos++;
        }
    }
    
    if (contAlgarismos > 0) {
        printf("\nTotal de algorismos encontrados: %d", contAlgarismos);
    }
    else {
        printf("\nNão foram encontrados algarismos.");
    }
    
    return 0;
}
