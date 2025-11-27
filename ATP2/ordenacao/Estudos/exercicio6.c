/*
FreqSort calculando a frequencia
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int freq;
} Elemento;

void ContarFreq(Elemento v[], int n);
void IntercalaFreq(Elemento v[], int p, int q, int r);
void FreqSort(Elemento v[], int p, int r);

int main() {
    
    int n = 8;
    
    Elemento *v = malloc(n * sizeof(Elemento));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i].valor);
        v[i].freq = 0;
    }
     
    ContarFreq(v, n);
    
    FreqSort(v, 0, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i].valor);
    }
    
    return 0;
    
}

void ContarFreq(Elemento v[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (v[j].valor == v[i].valor) {
                v[i].freq++;
            }
        }
    }
}

void IntercalaFreq(Elemento v[], int p, int q, int r) {
    int i, j, k;
    Elemento* w;
    
    i = p;
    j = q;
    k = 0;
    
    w = malloc(sizeof(Elemento) * (r - p));
    
    while (i < q && j < r) {
        if (v[i].freq >= v[j].freq) w[k++] = v[i++];
        else w[k++] = v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    
    for (i = p; i < r; i++) v[i] = w[i - p];
    
    free(w);
}

void FreqSort(Elemento v[], int p, int r) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        FreqSort(v, p, q);
        FreqSort(v, q, r);
        IntercalaFreq(v, p, q, r);
    }
}