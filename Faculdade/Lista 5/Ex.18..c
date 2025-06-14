/* 18. Escreva um programa em linguagem C para gerar, aleatoriamente, 10 números inteiros. Os
valores devem ser armazenados um vetor com 11 posições. Em seguida, o programa deve
solicitar duas entradas, um elemento e um índice. O índice deve ser um valor entre 0 e 9. O
elemento informado deve ser inserido na posição especificada, deslocando todos os elementos
seguintes. Imprimir o resultado. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    
    srand (time(NULL));
    
    int vetor[11];
    int elemento, indice;
    
    printf("Vetor: ");
    for (int i = 0; i < 10; i++) {
        vetor[i] = rand () % 11;
        printf("%d ", vetor[i]);
    }
    
    printf ("\nDigite um valor e um indice:");
    scanf("%d %d", &elemento, &indice);
    
    for (int i = 10; i > indice; i--) {
        vetor[i] = vetor[i - 1]; 
    }
    
    vetor[indice] = elemento;
    
    printf("\nNovo vetor:\n");
    for (int i = 0; i < 11; i++) {
        printf("%d ", vetor[i]);
    }
    
    return 0;
}
