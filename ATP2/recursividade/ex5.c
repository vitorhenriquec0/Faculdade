/*
O logaritmo na base 2, ou logaritmo binário, ocupa um lugar de extrema importância
no campo da matemática, particularmente nas disciplinas de ciência da computação, teoria
da informação e análise de algoritmos. A construção deste conceito remonta aos primeiros
desenvolvimentos da álgebra logarítmica, porém, sua proeminência foi verdadeiramente
afirmada com o surgimento das tecnologias digitais e computacionais, em que a base 2
tornou-se central devido à natureza binária dos sistemas digitais. Nesse sentido, construa
uma função recursiva que recebe um número natural n ≥ 1 e retorna o valor ⌊log2
n⌋.
*/

#include <stdio.h>

int logaritmo(int n);

int main()
{
    int n;
    scanf("%d", &n); 
    
    printf("⌊log2(%d)⌋ = %d", n, logaritmo(n));

    return 0;
}

int logaritmo(int n) {
    if (n <= 1) return 0;
    return 1 + logaritmo(n / 2);
}
