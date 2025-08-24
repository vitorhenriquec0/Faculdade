/*
Crie um programa que receba o nome de
dois arquivos A e B, e que copie todo o
conteúdo do arquivo A para o arquivo B,
substituindo todo o conteúdo previamente em B.
*/

#include <stdio.h>

int main() {
    
    FILE *arqA = fopen("arquivoA.txt", "r");
    FILE *arqB = fopen("arquivoB.txt", "w");

    if (arqA == NULL || arqB == NULL) {
        printf("Arquivos nao encontrados.");
        return 1;
    }

    int ch;
    while ((ch = fgetc(arqA)) != EOF) {
        fputc(ch, arqB);
    }

    fclose(arqA);
    fclose(arqB);
    
    return 0;
}