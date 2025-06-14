#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    
    srand(time(NULL));
    
    for (int m=0; m<7; m++) {
       for (int i=0; i<3; i++) {
        
        int n = (rand() % 6) + 1;
        
        printf("%d", n);
    }
    printf("\n");
    }
}
