#include <stdio.h>

int main () {

    int vetA[3];

    for (int i = 0; i < 3; i++) {
        printf("Numero %d:", i + 1);
        scanf("%d", &vetA);
    }

    int *vetAPtr = &vetA;

    printf("%p", vetAPtr);
}