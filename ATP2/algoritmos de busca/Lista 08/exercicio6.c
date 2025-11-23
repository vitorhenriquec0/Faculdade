/*
Descreva um algoritmo de busca para encontrar um elemento x em um vetor infinito or
denado em ordem crescente.
Dica! Como o vetor é infinito, então esse não tem limites à esquerda e à direta. Você pode
partir disso para supor algumas coisas.
*/

int auxBuscaExponencial(int v[], int x);
int BuscaBinaria(int v[], int m, int n, int x);

int auxBuscaExponencial(int v[], int x) {
    if (v[0] == x) return 0;

    int i = 1;

    while (v[i] < x) {
        i = i * 2;
    }

    return BuscaBinaria(v, i/2, i, x);
}

int BuscaBinaria(int v[], int p, int n, int x) {
    int e, m, d;
    e = p;
    d = n;

    while (e < d-1) {
        m = (e + d) / 2;
        if (v[m] < x) e = m;
        else d = m;
    }

    if (v[d] == x) return d;
    
    return -1;
}