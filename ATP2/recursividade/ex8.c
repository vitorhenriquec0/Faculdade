/*
A multiplicação camponesa, também referida como multiplicação russa ou egípcia, é
um método arcaico que se fundamenta em operações elementares de adição e duplicação.
Este procedimento, historicamente associado a diversas civilizações antigas, como a egíp-
cia, a russa e a babilônica, demonstra a engenhosidade dessas culturas ao realizar multi-
plicações de números arbitrários, mesmo na ausência de técnicas aritméticas sofisticadas
para a época. Dessa forma, a essência desse método reside na decomposição dos números
envolvidos, utilizando unicamente operações de soma, duplicação e redução pela metade.

Dessa forma, implemente uma função recursiva que realize a multiplicação camponesa.
Note: Dado um par de números naturais (x, y) para checar se o algoritmo implementado
produz valores corretos, basta checar o valor da multiplicação entre x e y, isto é, xy.
*/

#include <stdio.h>

int multiplicacaoCamponesa(int, int);

int main() {
    int x, y;

    printf("Digite os valores de x e y: ");
    scanf("%d %d", &x, &y);

    printf("\nMultiplicacao de x e y: %d", multiplicacaoCamponesa(x, y));

    return 0;
}

int multiplicacaoCamponesa(int x, int y) {
    if (x == 0) return 0;
    if (x == 1) return y;
    if (x % 2 == 0) {
        return multiplicacaoCamponesa(x/2, y*2);
    } else {
        return y + multiplicacaoCamponesa(x/2, y*2);
    }
}