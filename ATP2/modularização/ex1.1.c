/*
Crie uma função que receba um número inteiro positivo n e que imprima na saída
padrão da aplicação a seguinte árvore de asteriscos.
Exemplo: A saída a seguir é resultante da chamada da função com n = 5.
    *
   ***
  *****
 *******
*********
*/

#include <stdio.h>

void arvoreAsteriscos(int quantidade);

int main () {

    int quantidade;

    printf("Digite o tamanho da arvore: (ex.: 5)\n");
    scanf("%d", &quantidade);

    arvoreAsteriscos(quantidade);

    return 0;
}

void arvoreAsteriscos(int quantidade) {

    if (quantidade == 0) {
        printf("Forneça um número inteiro e positivo.\n");
        return;
    }

    for (int i = 1; i <= quantidade; i++) {

        for (int espaco = 1; espaco <= quantidade - i; espaco++) {
            printf(" ");
        }

        for (int j = 1; j <= (2 * i - 1); j++) {
            printf("*");
        }
        printf("\n");
    }
}
