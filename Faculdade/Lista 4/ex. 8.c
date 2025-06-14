#include <stdio.h>

int main () {
    
    printf("Numeros divisiveis entre 1 e 200:\n");
    
    for (int i=4; i<201; i+=4) {
        printf("%d\t", i);
    }
    return 0;
}