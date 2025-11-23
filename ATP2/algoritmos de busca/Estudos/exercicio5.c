/*
Dado um vetor de inteiros ordenado em ordem crescente,
encontre a posição inicial e final de um dado valor alvo.
Se o alvo não for encontrado no vetor, retorne {-1, -1}.
*/

#include <stdio.h>

int BuscaPrimeiro(int v[], int n, int x);
int BuscaUltimo(int v[], int n, int x);

int main() {
    int v[] = {5, 7, 7, 8, 8, 10};
    int n = 6;
    int x = 8;

    int primeiro = BuscaPrimeiro(v, n, x);
    int ultimo = BuscaUltimo(v, n, x);

    printf("Alvo: %d\n", x);
    printf("Primeira ocorrencia: indice %d\n", primeiro);
    printf("Ultima ocorrencia: indice %d\n", ultimo);

    // Caso não encontre, ambos serão -1
    if (primeiro == -1) {
        printf("Elemento nao encontrado.\n");
    } else {
        printf("Total de ocorrencias: %d\n", ultimo - primeiro + 1);
    }

    return 0;
}

int BuscaPrimeiro(int v[], int n, int x) {
    int e = 0; 
    int d = n - 1;
    int res = -1;

    while (e <= d) {
        int m = (e + d) / 2;

        if (v[m] == x) {
            res = m;

            d = m - 1;
        } else if (v[m] < x) {
            e = m + 1;
        } else {
            d = m - 1;
        }
    }
    return res;
}

int BuscaUltimo(int v[], int n, int x) {
    int e = 0; 
    int d = n - 1;
    int res = -1;

    while (e <= d) {
        int m = (e + d) / 2;

        if (v[m] == x) {
            res = m;

            e = m + 1;
        } else if (v[m] < x) {
            e = m + 1;
        } else {
            d = m - 1;
        }
    }
    return res;
}