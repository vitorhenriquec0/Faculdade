/*
Pense que você está trabalhando em um projeto de programação e se depara com
um problema interessante: gerar todas as combinações possíveis de parênteses, em que
cada parêntese aberto é devidamente fechado. Esse problema, embora pareça simples à
primeira vista, requer uma abordagem cuidadosa para garantir que todas as combinações
geradas sejam válidas, ou seja, que não existam parênteses abertos sem seu correspondente
fechamento. A tarefa é implementar uma função recursiva que receba um número natural
n ≥ 1, representando o número de pares de parênteses, e que produza todas as combi-
nações possíveis desses pares. O problema está em assegurar que cada combinação ger-
ada seja estruturalmente correta, com todos os parêntese aninhados e fechados na ordem
correta. Este tipo de problema é comum em áreas que envolvem análise de expressões
matemáticas ou linguagem de programação, em que a correta abertura e fechamento de
parênteses é fundamental.
*/

#include <stdio.h>
#include <string.h>

void gerar(int abertos, int fechados, char *atual, int pos);

int main() {
    int n;
    scanf("%d", &n);
    
    char atual[2 * n + 1];

    gerar(n, n, atual, 0);

    return 0;
}

void gerar(int abertos, int fechados, char *atual, int pos) {
    if (abertos == 0 && fechados == 0) {
        atual[pos] = '\0';
        printf("%s\n", atual);
        return;
    }

    if (abertos > 0) {
        atual[pos] = '(';
        gerar(abertos - 1, fechados, atual, pos + 1);
    }

    if (fechados > abertos) {
        atual[pos] = ')';
        gerar(abertos, fechados - 1, atual, pos + 1);
    }
}