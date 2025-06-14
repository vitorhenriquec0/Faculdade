#include <stdio.h>

int main() {
    
    int mat[2][3];
    
    printf("\nDigite os 6 elementos da matriz 2x3:");
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &mat[i][j]);
            printf("%2d ", mat[i][j]);
        }
        printf("\n");
    }
    
    printf("\nMatriz transposta 3x2:\n");
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("%2d ", mat[j][i]);
        }
        printf("\n");
    }
    
    return 0;
}
