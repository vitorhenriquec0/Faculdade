/*
Crie um programa que receba o nome de um arquivo A contendo uma sequência
de números inteiros separados por linha, e armazene esses números em um vetor. Além
disso, realize os seguintes itens:
a) Imprima a quantidade de números lidos.
b) Imprima o maior número lido.
c) Imprima o menor número lido.
d) Imprima a média aritmética x dos números lidos supondo que N seja a quantidade de números lidos.
e) Imprima o desvio padrão sX dos números lidos
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *arquivo;
    char nomeArquivo[100];
    int *vetor = NULL;
    int capacidade = 10; // capacidade inicial do vetor
    int n = 0; // quantidade de numeros lidos
    int numero;

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    vetor = malloc(capacidade * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria\n");
        return 1;
    }

    while (fscanf(arquivo, "%d", &numero) == 1) {
        if (n == capacidade) {
            capacidade *= 2;
            vetor = realloc(vetor, capacidade * sizeof(int));
            if (vetor == NULL) {
                printf("Erro ao realocar memoria\n");
                return 1;
            }
        }
        vetor[n++] = numero;
    }

    fclose(arquivo);

    if (n == 0) {
        printf("Nenhum numero encontrado no arquivo.\n");
        free(vetor);
        return 0;
    }

    int maior = vetor[0];
    int menor = vetor[0];
    double soma = 0.0;

    for (int i = 0; i < n; i++) {
        if (vetor[i] > maior) maior = vetor[i];
        if (vetor[i] < menor) menor = vetor[i];
        soma += vetor[i];
    }

    double media = soma / n;

    double somaQuadrados = 0.0;
    for (int i = 0; i < n; i++) {
        somaQuadrados += pow(vetor[i] - media, 2);
    }
    double desvioPadrao = sqrt(somaQuadrados / (n - 1));
    
    printf("\n");
    printf("a) Quantidade de numeros lidos: %d\n", n);
    printf("b) Maior numero: %d\n", maior);
    printf("c) Menor numero: %d\n", menor);
    printf("d) Media aritmetica: %.2f\n", media);
    printf("e) Desvio padrao: %.2f\n", desvioPadrao);

    free(vetor);
    return 0;
}