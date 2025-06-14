#include <stdio.h>

int main ()
{
    int matA[5][5];
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == j) {
                matA[i][j] = 1;
            }
            else {
                matA[i][j] = 0;
            }
        }
    }
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d ", matA[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}