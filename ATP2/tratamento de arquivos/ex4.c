/*
Crie um programa que conte quantas linhas um arquivo de texto possui.
*/

#include <stdio.h>

int main() {

    FILE *fp = fopen("exercicio1.txt", "r");

    if (fp == NULL) {
        printf("Arquivo nao encontrado.");
        return 1;
    }

    int linhas = 0;
    char ch;
    while((ch = fgetc(fp)) != EOF) {
        if (ch == '\n') {
            linhas++;
        }
    }
    fclose(fp);

    printf("Quanrtidade de linhas: %d", linhas);

    return 0;
}
