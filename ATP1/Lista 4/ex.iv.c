#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    
    srand(time(NULL));
    
    int um=0, dois=0, tres=0, quatro=0, cinco=0, seis=0;
    
    for (int i=0; i<6000; i++) {
        
       int n = ((rand() % 6) +1);
        
       switch (n) {
           case 1: um += 1; break;
           case 2: dois += 1; break;
           case 3: tres += 1; break;
           case 4: quatro += 1; break;
           case 5: cinco += 1; break;
           case 6: seis += 1; break;
       }
    }
    
    printf("\nFace 1: %d", um);
    printf("\nFace 2: %d", dois);
    printf("\nFace 3: %d", tres);
    printf("\nFace 4: %d", quatro);
    printf("\nFace 5: %d", cinco);
    printf("\nFace 6: %d", seis);
    
    return 0;
}
