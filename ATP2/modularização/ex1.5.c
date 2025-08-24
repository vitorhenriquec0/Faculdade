/*
Realize os seguintes itens.
a) Crie uma função que receba um vetor com n números reais e que retorne à função chamadora
o maior número no vetor.
b) Crie uma função que receba um vetor com n números reais e que retorne à função chamadora
o menor número no vetor.
c) Crie uma função que receba um vetor com n números reais e que retorne à função chamadora
o maior e o menor número no vetor.
Dica: Use passagem por referência para realizar o "retorno" do número maior e menor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maiorNumero(int vetor[], int tamanho);
int menorNumero(int vetor[], int tamanho);
void numeroMaiorMenor(int vetor[], int tamanho, int *maior, int *menor);

int main() {

    int tamanho;
    
    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &tamanho);

    int vetor[tamanho - 1];
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
    }

    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d, ", vetor[i]);
    }
    printf("\n\n");

    printf("a) O maior numero do vetor eh: %d\n", maiorNumero(vetor, tamanho));
    printf("b) O menor numero do vetor eh: %d\n", menorNumero(vetor, tamanho));
    
    int maiorResultado, menorResultado;
    numeroMaiorMenor(vetor, tamanho, &maiorResultado, &menorResultado);
    printf("c) Pela funcao de referencia:\nMaior = %d\nMenor = %d\n", maiorResultado, menorResultado);

    return 0;
}

int maiorNumero(int vetor[], int tamanho) {
    int maior = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

int menorNumero(int vetor[], int tamanho) {
    int menor = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] < menor) {
            menor = vetor[i];
        }
    }
    return menor;
}

void numeroMaiorMenor(int vetor[], int tamanho, int *maior, int *menor) {

    *maior = vetor[0];
    *menor = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > *maior) {
            *maior = vetor[i];
        } else if (vetor[i] < *menor) {
           *menor = vetor[i];
        }
    }
}