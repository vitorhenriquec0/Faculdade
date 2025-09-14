#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    FILE *arquivo;
    char nomeArquivo[100];

    scanf("%s", nomeArquivo);

    arquivo = fopen(nomeArquivo, "r+");

    double *vetor;
    int capacidade = 10;

    vetor = malloc(capacidade * sizeof(int));

    int i = 0;
    while(fscanf(arquivo, "%lf", &vetor[i]) == 1) {
        i++;
        if (i >= capacidade) {
            capacidade *= 2;
            vetor = realloc(vetor, capacidade * sizeof(double));
        }
    }

    rewind(arquivo);

    // a) f(x) = x2
    for (int j = 0; j < i; j++) {
        fprintf(arquivo, "%.2f ", pow(*(vetor + j), 2));
    }

    // b) f(x) = sqrt(1 + x2)

    for (int j = 0; j < i; j++) {
        fprintf(arquivo, "%.2f ", sqrt(1 + *(vetor + j) * *(vetor + j)));
    }
    
    // c) f(x) = sin(x) + cos(x)

    for (int j = 0; j < i; j++) {
        fprintf(arquivo, "%.2f ", sin(*(vetor + j)) + cos(*(vetor + j)));
    }

    return 0;
}