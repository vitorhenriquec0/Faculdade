/*
Crie um programa que leia a partir de um arquivo um número inteiro e escreva no
mesmo arquivo o número consecutivo, substituindo o número anterior.
*/

#include <stdio.h>

int main() {
    FILE *fp;

    int numero;

    fp = fopen("exercicio1.txt", "w");

    scanf("%d", &numero);

    if (fp != "NULL") {
        fprintf(fp, "%d\n", numero + 1);
        fclose(fp);
    }
    return 0;
}