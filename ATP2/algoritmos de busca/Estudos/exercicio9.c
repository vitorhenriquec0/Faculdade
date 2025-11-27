/*
Implemente a função pra encontrar um pico, mas de forma recursiva
*/

int PicoRec(int v[], int e, int d) {

    if (e == d) return e;

    int m = (e + d) / 2;

    if (v[m] < v[m + 1]) return PicoRec(v, m + 1, d);
    if (v[m] > v[m + 1]) return PicoRec(v, e, m);
}

/* Forma iterativa

int pico(float v[], int n) {
    if (n == 1) return 0;

    if (v[0] >= v[1]) return 0;

    for (int i = 1; i < n - 1; i++) {
        if (v[i-1] <= v[i] && v[i+1] <= v[i]) return i;
    }

    if (v[n-1] >= v[n-2]) return n-1;

    return -1; // caso raro, por segurança

}

*/