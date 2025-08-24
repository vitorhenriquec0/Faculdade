/*
Crie um programa que receba o nome de um arquivo A e que imprima na saída
padrão da aplicação a quantidade de caracteres, a quantidade de palavras, e a quantidade
de linhas presentes no arquivo A.
*/

#include <stdio.h>

int main() {

    char arquivoLido[50];

    int caracteres = 0;
    int palavras = 0;
    int linhas = 0;

    int dentro_da_palavra = 0;

    printf("Digite o arquivo a ser lido:");
    scanf("%s", arquivoLido);

    FILE *arq8 = fopen(arquivoLido, "r");

    if (arq8 == NULL) {
        printf("Arquivo nao encontrado");
        return 1;
    }

    int ch;
    while ((ch = fgetc(arq8)) != EOF) {
        caracteres++;
        
        if (ch == '\n') {
            linhas++;
        }

        if (ch == ' ' || ch == '\n' || ch == '\t') {
            dentro_da_palavra = 0;
        } else if (dentro_da_palavra == 0) {
            dentro_da_palavra = 1;
            palavras++;
        }
    }

    if (caracteres > 0) {
        linhas++;
    }

    fclose(arq8);

    printf("\nCaracteres: %d\n", caracteres);
    printf("Linhas: %d\n", linhas);
    printf("Palavras: %d\n", palavras);

    return 0;
}