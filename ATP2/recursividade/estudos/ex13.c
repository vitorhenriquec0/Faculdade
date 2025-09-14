/*
A multiplicac¸ao de dois n ˜ umeros inteiros pode ser feita atrav ´ es de somas sucessivas. ´
Proponha um algoritmo recursivo Multip Rec(n1,n2) que calcule a multiplicac¸ao de dois ˜
inteiros.
*/

#include <stdio.h>

int MultipRec(int x, int y);

int main() {
    int x, y;
    scanf("%d %d", &x, &y);

    printf("Multiplicacao: %d", MultipRec(x, y));

    return 0;
}

int MultipRec(int x, int y) {
    if (x == 0) return 0;
    return y + MultipRec(x - 1, y);
}