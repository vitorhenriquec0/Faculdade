/*
Implemente a função SelectionSort em C.
Ordene em ordem DECRESCENTE (do maior para o menor).
*/

void SelectionSort(int v[], int n) {
    int i, j, x, temp;

    for (i = 0; i < n-1; i++) {
        x = i;
        for (j = i+1; j < n; j++) {
            if (v[j] > v[x]) x = j;
        }

        if (x != i) {
            temp = v[i];
            v[i] = v[x];
            v[x] = temp;
        }
    }
}