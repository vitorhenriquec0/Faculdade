/*
Crie um programa que receba o nome de três arquivos de texto A, B e C, e que
concatene o conteúdo dos arquivos A e B, nessa ordem, gerando um arquivo C.
*/

#include <stdio.h>

int main() {
    FILE *arqA = fopen("arquivoA.txt", "r");
    FILE *arqB = fopen("arquivoB.txt", "r");
    FILE *arqC = fopen("arquivoC.txt", "w+");

    if (arqA == NULL || arqB == NULL || arqC == NULL) {
        printf("Arquivo nao encontrado.");
        return 1;
    }

    int ch;
    while((ch = fgetc(arqA)) != EOF) {
        fputc(ch, arqC);
    }
    fprintf(arqC, "\n");
    while((ch = fgetc(arqB)) != EOF) {
        fputc(ch, arqC);
    }

    fclose(arqA);
    fclose(arqB);
    fclose(arqC);

    return 0;
}