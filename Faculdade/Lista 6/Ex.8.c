#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 5

int main ()
{
    int matA[n][n];
    char ja_consta;
    
    srand (time(NULL));
    
    printf("Matriz A:\n");
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            
           do {
            ja_consta = 0;
            matA[i][j] = rand() % 100;

    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (x > i || (x == i && y >= j)) break;
            
            if (matA[x][y] == matA[i][j]) {
                ja_consta = 1;
                break;
            }
        }
        if (ja_consta) break; }
    } while (ja_consta);
    
    printf("%2d ", matA[i][j]);
    
        }
    
    printf("\n");
    }

    
    return 0;
}