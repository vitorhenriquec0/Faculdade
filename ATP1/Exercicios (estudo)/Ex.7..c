/* Ler um vetor de N números inteiros.
Calcular e exibir: a média dos elementos, o maior e o menor elemento,
e quantos números são pares.
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    
    srand(time(NULL));
    
    int n = rand () % 50 + 1;
    
    int vetor[n];
    int somaElementos = 0, qtdElementos = 0;
    int indiceMaiorElemento = 0, indiceMenorElemento = 0;
    int qtdPares = 0;
    
    for (int i = 0; i < n; i++) {
        vetor[i] = rand() % 100;
        
        somaElementos += vetor[i];
        
        if (vetor[i] > indiceMaiorElemento) {
            indiceMaiorElemento = i;
        }
        if (vetor[i] < vetor[indiceMenorElemento]) {
            indiceMenorElemento = i;
        }
        if(vetor[i] % 2 == 0) {
            qtdPares++;
        }
    }
    
    printf("\nSoma de todos os %d elementos: %d", n, somaElementos);
    printf("\nMédia dos elementos: %d", somaElementos / n);
    printf("\nMaior elemento: %d", vetor[indiceMaiorElemento]);
    printf("\nMenor elemento: %d", vetor[indiceMenorElemento]);
    printf("\nQuantidade de elementos pares: %d", qtdPares);
    
    return 0;
}
