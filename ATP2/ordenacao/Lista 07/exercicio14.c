/*
Construa um programa que receba uma sequência de N vetores d-dimensionais ordena
dos em ordem crescente, e que mescle todos esses vetores, permitindo imprimir na saída
padrão da aplicação o vetor Nd-dimensional ordenado em ordem crescente.

-> Minha interpretação:
-> Por exemplo, se N = 3, são 3 vetores
-> d-dimensionais significa que todos possuem tamanho igual a d
-> Se é pra mesclar, convem utilizar o Intercala do Merge Sort
-> Cada vetor já está ordenado, então tem que adaptar o Intercala pra
   receber dois vetores e retornar um novo vetor, que vai ser intercalado
   com o próximo.
*/

#include <stdio.h>
#include <stdlib.h>

int* IntercalaVetores(int v1[], int n1, int v2[], int n2);

int main() {
    int N, d;
    scanf("%d %d", &N, &d);

    int **mat = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        mat[i] = malloc(d * sizeof(int));
        for (int j = 0; j < d; j++) scanf("%d", &mat[i][j]);
    }


    // começando com o primeiro vetor
    int *resultado = malloc(d * sizeof(int));
    for (int i = 0; i < d; i++) resultado[i] = mat[0][i];
    int tamanho = d;

    for (int i = 1; i < N; i++) {
        int *novo = IntercalaVetores(resultado, tamanho, mat[i], d);
        free(resultado);
        resultado = novo;
        tamanho += d;
    }

    printf("\n-> Vetor mesclado e ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    free(resultado);
    for (int i = 0; i < N; i++) free(mat[i]);
    free(mat);

    return 0;
}

int* IntercalaVetores(int v1[], int n1, int v2[], int n2) {
    int *result = malloc((n1 + n2) * sizeof(int));
    int i = 0, j = 0, k = 0;

    while (i < n1 && j < n2) {
        if (v1[i] <= v2[j]) result[k++] = v1[i++];
        else result[k++] = v2[j++];
    }

    while (i < n1) result[k++] = v1[i++];
    while (j < n2) result[k++] = v2[j++];

    return result;
}


