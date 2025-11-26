/*
Dividir o vetor em 3 partes usando dois números de corte, $m$ e $M$.
Parte 1: Números menores ou iguais a $m$.
Parte 2: Números entre $m$ e $M$ (o "miolo").
Parte 3: Números maiores ou iguais a $M$.
Isso é uma evolução do Quicksort. No Quicksort normal, temos 1 pivô e 2 regiões. Aqui, temos 3 regiões.
*/

void SeparaTres(int v[], int n, int m, int M) {
    int i = 0;
    int e = 0;
    int d = n - 1;
    int temp;

    while (i <= d) {
        if (v[i] < m) {
            temp = v[i];
            v[i] = v[e];
            v[e] = temp;
            e++;
            i++;
        } else if (v[i] > M) {
            temp = v[i];
            v[i] = v[d];
            v[d] = temp;
            d--;
        } else {
            i++;
        }
    }
}