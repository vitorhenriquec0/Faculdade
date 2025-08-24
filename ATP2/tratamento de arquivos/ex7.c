/*
Crie um programa que receba o nome de um arquivo A contendo uma sequência de
números separados por linha, e armazene esses números em um vetor.
*/

#include <stdio.h>

#define CAPACIDADE_MAXIMA 100

int main() {

    int vetor[CAPACIDADE_MAXIMA];
    char nomeArquivo[50];
    int contador = 0;

    printf("Digite o nome do arquivo de entrada:");
    scanf("%s", nomeArquivo);

    FILE *arq = fopen(nomeArquivo, "r");

    if (arq == NULL) {
        printf("Arquivo nao encontrado");
        return 1;
    }

    while (contador < CAPACIDADE_MAXIMA && fscanf(arq, "%d", &vetor[contador]) == 1) {
        contador++;
        fgetc(arq);
    }

    fclose(arq);

    for (int i = 0; i < contador; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}