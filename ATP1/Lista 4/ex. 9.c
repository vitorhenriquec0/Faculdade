#include <stdio.h>

int main()
{ 
    int a, b, aux;
    
    a = 0;
    b = 1;
    
    for (int i=0; i < 15; i++) {
        aux = a + b;
        a = b;
        b = aux;
        
        printf("%d\n", aux);
    }
    
    return 0;
}
    
    
