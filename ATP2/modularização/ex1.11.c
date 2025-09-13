/*
Crie uma função que receba um vetor com n números inteiros e que inverta a ordem
dos elementos no vetor, ou seja, faça com que o primeiro elemento mova-se para o último,
o segundo para o penúltimo, e assim por diante.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void reverseOrder(int *, int);
void show(int *, int);

int main() {

    srand(time(NULL));

    int n;

    printf("Enter the vector size: ");
    scanf("%d", &n);

    int vector[n];

    for (int i = 0; i < n; i++) {
        vector[i] = rand() % 30;
    }

    printf("\nOriginal vector: ");
    show(vector, n);

    printf("\nReverse vector: ");
    reverseOrder(vector, n);
    show(vector, n);
}

void reverseOrder(int *vector, int n) {
    int *start = vector;
    int *end = vector + n - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

void show(int *vector, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");
}