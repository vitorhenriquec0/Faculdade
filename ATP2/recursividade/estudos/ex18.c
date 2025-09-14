/*
Escreva uma func¸ao recursiva ImprimeSerie(i,j,k). Esta func¸ ˜ ao imprime na tela a s ˜ erie ´
de valores do intervalo [i,j], com incremento k.
*/

#include <stdio.h>

void imprimeSerie(int, int, int);

int main() {
    int i, j, k;
    scanf("%d%d%d", &i, &j, &k);

    if (i > j) {
        printf("i deve ser menor que j");
        return 1;
    }

    imprimeSerie(i, j, k);

    return 0;
}

void imprimeSerie(int i, int j, int k) {
    if (i > j) return 0;
    printf("%d ", i);
    imprimeSerie(i + k, j, k);
}
