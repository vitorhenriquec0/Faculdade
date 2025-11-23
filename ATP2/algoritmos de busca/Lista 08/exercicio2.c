/*
Com base no mesmo exercício anterior, em vez de usar BUSCALINEAR(A, X) empregue o
algoritmo de BUSCABINÁRIA(A, X).
Note: Lembre-se que não há restrições em A, e que o algoritmo BUSCABINÁRIA(A, X)
possui uma certa restrição. Você deve resolver isso!
*/

#include <stdio.h>

int BuscaBinaria(int v[], int n, int x);
void BubbleSort(int v[], int n);

int main () {
    int v[7] = {3, 5, 10, 15, 17, 19, 25};
    int n = 7;
    int x;

    scanf("%d", &x);

    BubbleSort(v, n);

    int resultado = BuscaBinaria(v, n, x);
    printf("%d", resultado);

    return 0;
}

int BuscaBinaria(int v[], int n, int x) {
    int e, m, d;
    e = -1;
    d = n;

    while (e < d - 1) {
        m = (e + d) / 2;
        if (v[m] < x) e = m;
        else d = m;
    }

    if (d < n && v[d] == x) {
        return d;
    }

    return -1;
}

void BubbleSort(int v[], int n) {
    int aux;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (v[j] > v[j + 1]) {
                aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}