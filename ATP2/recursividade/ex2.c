#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int soma(int **A, int m, int n);

int main() {
    int **A;
    int m, n;

    scanf("%d%d", &m, &n);

    srand(time(NULL));

    A = calloc(m, sizeof(int *));
    for (int i = 0; i < m; i++) {
        *(A + i) = calloc(n, sizeof(int));
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            *(*(A + i) + j) = rand() % 30;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", *(*(A + i) + j));
        }
        printf("\n");
    }

    printf("\n\nSomatorio dos elementos: %d", soma(A, m, n));

    for (int i = 0; i< m; i++) { 
        free(A[i]);
    }
    free(A);

    return 0;

}   

int soma(int **A, int m, int n) {
    if (m == 0) return 0;
    if (n == 0) return soma(A, m - 1, n);

    return A[m - 1][n - 1] + soma(A, m, n -1);
}