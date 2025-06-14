/* 22. Escreva um programa em linguagem C para que usuário digite um nome. A entrada deve ser
armazenada em uma variável nome, declarada com 40 caracteres. Em seguida, o programa
deve percorrer a string nome e apresentar cada letra em uma linha. O programa deve
percorrer a string somente até a última letra do nome. Ao final, o programa deverá
apresentar também o total de algarismos existentes. */

#include <stdio.h>

int main() {
    char nome[40];
    char c;
    int contAlgarismos = 0;
    int i = 0;
    
    printf("Digite o nome: \n");
    scanf(" %[^\n]", nome);
    
    for (int i = 0; nome[i] != '\0'; i++) {
        printf("\n%da letra: %c", i + 1, nome[i]);
    }
    
    for (int i = 0; nome[i] != '\0'; i++) {
        c = nome[i];
        
        if (c >= '0' && c <= '9') {
            contAlgarismos ++;
        }
    }
    
    if (contAlgarismos > 0) {
        printf("\nTotalização de algarismos encontrados: %d", contAlgarismos);
    }
    else {
        printf("\nNenhum algarismo encontrado.");
    }
    
    return 0;
}
