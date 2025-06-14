#include <stdio.h>

int main () {
    
    int soma=0;
    
    for (int i=0; i<=500; i+=2) {
        soma += i;
    }
    
    printf("A soma dos termos pares de 0 até 500 é: %d", soma);
    
    return 0;
}