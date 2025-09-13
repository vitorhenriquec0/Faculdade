#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int somatorio(int **A, int m, int n);

int main() {

    srand(time(NULL));

    int **A;
    int m, n;

    scanf("%d%d", &m, &n);

    A = calloc(m, sizeof(int));
    for (int i = 0; i < m; i++) {
        *(A + i) = calloc(n, sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *((A + i) + j) = rand() % 30;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *((A + i) + j));
        }
        printf("\n");
    }

    printf("\nSomatorio dos elementos na diagonal secundária: %d", somatorio(A, m, n));

    free(A);
}

int somatorio(int **A, int m, int n) {
    if()
}

