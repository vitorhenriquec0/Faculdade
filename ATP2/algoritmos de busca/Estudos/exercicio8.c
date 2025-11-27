/*
Implementar a função de Busca Binária para ponto fixo recursiva
*/

int BuscaPontoFixoRec(int v[], int e, int d) {
    if (e > d) return -1;

    int m = (e + d) / 2;

    if (v[m] == m) return m;

    if (v[m] < m) return BuscaPontoFixoRec(v, m + 1, d);
    else return BuscaPontoFixoRec(v, e, m - 1);
}