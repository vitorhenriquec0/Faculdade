/*
Escreva uma func¸ao recursiva SomaSerie(i,j,k). Esta func¸ ˜ ao devolve a soma da s ˜ erie de ´
valores do intervalo [i,j], com incremento k.
*/

#include <stdio.h>

int somaSerie(int, int, int);

int main() {
    int i, j, k;

    scanf("%d%d%d", &i, &j, &k);

    if (i > j) {
        printf("i deve ser maior que j");
        return 1;
    }

    printf("%d", somaSerie(i, j, k));

    return 0;    
}

int somaSerie(int i, int j, int k) {
    if (i > j) return 0;
    return i + somaSerie(i + k, j, k);
}