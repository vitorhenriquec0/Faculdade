/*
Crie um programa que mostre o tamanho de um arquivo.
*/

#include <stdio.h>

int main() {

    FILE *fp = fopen("exercicio1.txt", "rb");

    if (fp == NULL) {
        printf("Arquivo nao encontrado!");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long tamanho = ftell(fp);
    fclose(fp);

    printf("Tamanho do arquivo 'exercicio1.txt': %ld bytes", tamanho);
    return 0;
}