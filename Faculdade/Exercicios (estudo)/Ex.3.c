#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
    int matA[5][3];
    int maior[3] = {0};
    
    srand(time(NULL));
    
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matA[i][j] = rand() % 100;
            printf("%2d ", matA[i][j]);
        }
        printf("\n");
    }
    
    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (matA[i][j] > maior[j]) {
                maior[j] = matA[i][j];
            }
        }
    }
    
    for (int j = 0; j < 3; j++)
    {
        printf("O maior elemento da coluna %d é: %d\n", j + 1, maior[j]);
    }
    
    return 0;
}
