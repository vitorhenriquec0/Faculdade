/*
Implemente o bubble sort decrescente e inteligente (se o vetor estiver ordenado, pare)
*/

void BubbleSort(int v[], int n) {

    for (int i = 0; i < n; i++) {
        int troca = 0;
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j+1] < v[j]) {
                int temp = v[j];
                v[j] = v[j+1];
                v[j+1] = temp;

                troca = 1;
            }
        }

        if (troca == 0) return; // otimização
    }
}