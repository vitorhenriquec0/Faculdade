#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int freq;
    int originalIndex;
} Element;

void Intercala(Element* v, int p, int q, int r);
void MergeSort(int p, int r, Element* v);


int main() {
    int N;
    scanf("%d", &N);

    int *vetorOriginal = malloc(N * sizeof(int));
    Element *elements = malloc(N * sizeof(Element));

    for (int i = 0; i <  N; i++) {
        scanf("%d", &vetorOriginal[i]);
    }

    for (int i = 0; i < N; i++) {
        elements[i].data = vetorOriginal[i];
        elements[i].freq = 0;
        elements[i].originalIndex = i;
    }

    MergeSort(0, N, elements);

    printf("\n--- Array ordenado por valor ---\n");
    for (int i = 0; i < N; i++) {
        printf("Valor: %d, Idx: %d\n", elements[i].data, elements[i].originalIndex);
    }

    Element* elementosUnicos = malloc(N * sizeof(Element));
    int count = 0;

    int i = 0;
    while (i < N) {

        int valorAtual = elements[i].data;
        int indiceOriginalAtual = elements[i].originalIndex;
        int countAtual = 0;

        int j = i;
        while (j < N && elements[j].data == valorAtual) {
            countAtual++;
            j++;
        }

        elementosUnicos[count].data = valorAtual;
        elementosUnicos[count].freq = countAtual;
        elementosUnicos[count].originalIndex = indiceOriginalAtual;

        count++;
        i = j;
    }


}

void Intercala(Element* v, int p, int q, int r) {
    int i = p;
    int j = q;
    int k = 0;

    Element* w = malloc((r - p) * sizeof(Element));

    while (i < q && j < r) {
        if (v[i].data < v[j].data || v[i].data == v[j].data && v[i].originalIndex < v[j].originalIndex) w[k++] = v[i++];
        else w[k++] = v[j++]; 
    }

    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];

    for (i = p; i < r; i++) v[i] = w[i - p];

    free(w);

}

void MergeSort(int p, int r, Element* v) {
    if (p < r - 1) {
        int q = (p + r) / 2;
        MergeSort(p, q, v);
        MergeSort(q, r, v);
        Intercala(v, p, q, r);
    }
}