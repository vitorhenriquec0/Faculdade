#include <stdio.h>

int main () {
    
    int n;
    
    printf("Digite o número:");
    scanf("%d", &n);
    
    for (int i=0; i<11; i++) {
        printf("\n%d x %d = %d",n, i, n*i);
    }
    return 0;
}