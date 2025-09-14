/*
Implemente uma função recursiva em C que verifique se uma string é um palíndromo.
Uma string é um palíndromo se ela é igual quando lida de trás para frente.
*/

#include <stdio.h>
#include <string.h>

int ehPalindromo(char *str, int inicio, int fim);

int main() {
    char str[100];
    
    printf("Digite uma string: ");
    scanf("%s", str);
    
    int n = strlen(str);
    
    if (ehPalindromo(str, 0, n - 1)) {
        printf("'%s' eh um palindromo", str);
    } else {
        printf("'%s' nao eh um palindromo", str);
    }
    
    return 0;
    
}

int ehPalindromo(char *str, int inicio, int fim) {
    if (inicio >= fim) return 1;
    
    if (str[inicio] != str[fim]) return 0;
    
    return ehPalindromo(str, inicio + 1, fim - 1);
}