/*
Fac¸a uma func¸ao recursiva que calcule o valor da s ˜ erie S descrita a seguir para um valor ´
n > 0 a ser fornecido como parametro para a mesma. 
*/

#include <stdio.h>

float serie(int n, int inicio);

int main() {
    int n;
    scanf("%d", &n);

    printf("%.2f ", serie(n, 1));

    return 0;
}

float serie(int n, int inicio) {
    if (inicio > n) return 0;
    return ((1 + inicio * inicio) / inicio) + serie(n, inicio + 1);
}