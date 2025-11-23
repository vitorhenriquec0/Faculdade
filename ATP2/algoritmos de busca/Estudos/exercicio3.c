/*
Você recebe uma matriz $M \times N$ de inteiros com as seguintes propriedades

Inteiros em cada linha são ordenados da esquerda para a direita.
O primeiro inteiro de cada linha é maior que o último inteiro da linha anterior.

Escreva um algoritmo que procure um valor alvo nessa matriz.
Se encontrar, retorne 1 (true), caso contrário 0 (false)
Restrição: Complexidade deve ser $O(\log(M \times N))$.
*/

#include <stdio.h>

#define COLUNAS 4

int BuscaBinaria(int mat[][COLUNAS], int x, int m, int n);

int main() {
    int matriz[3][COLUNAS] = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    int alvo = 51;
    
    if (BuscaBinaria(matriz, alvo, 3, COLUNAS)) {
        printf("Encontrado!\n");
    } else {
        printf("Nao encontrado.\n");
    }

    return 0;
}

int BuscaBinaria(int mat[][COLUNAS], int x, int m, int n) {
    int e = 0;
    int d = (m * n) - 1;

    while (e < d) {
        int meio = (e + d) / 2;

        int linha = meio / n;
        int coluna = meio % n;

        if (mat[linha][coluna] < x) {
            e = meio + 1;
        } else if (mat[linha][coluna] > x) {
            d = meio - 1;
        } else {
            return 1;
        }
    }
    return 0;
}