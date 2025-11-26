/*
Implemente o algoritmo de ordenação QUICKSORT(A) utilizando dois pivôs tanto crescente
tanto decrescente.
*/

#include <stdio.h>

void DualPivotQuickSort(int p, int r, int v[]);

int main() {

    int v[] = {89, 29, 43, 19, 2, 8, 9, 15};
    int n = 8;

    printf("\nVetor nao ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    DualPivotQuickSort(0, n - 1, v);

    printf("\n\nVetor ordenado por Quick Sort com dois pivos: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    return 0;
}

void DualPivotQuickSort(int p, int r, int v[]) {

    if (p < r) {

        if (v[p] > v[r]) {
            int temp = v[p];
            v[p] = v[r];
            v[r] = temp;
        }

        int piv1 = v[p];
        int piv2 = v[r];

        int lt = p + 1;
        int gt = r - 1;
        int i = p + 1;

        while (i <= gt) {
            if (v[i] < piv1) {
                int temp = v[i];
                v[i] = v[lt];
                v[lt] = temp;
                lt++;
                i++;
            } else if (v[i] > piv2) {
                int temp = v[i];
                v[i] = v[gt];
                v[gt] = temp;
                gt--;
            } else {
                i++;
            }
        }

        lt--;
        gt++;
        
        int temp1 = v[p];
        v[p] = v[lt];
        v[lt] = temp1;

        int temp2 = v[r];
        v[r] = v[gt];
        v[gt] = temp2;

        DualPivotQuickSort(p, lt - 1, v);
        DualPivotQuickSort(lt + 1, gt - 1, v);
        DualPivotQuickSort(gt + 1, r, v);
    }
}

/*
void DualPivotQuickSort(int p, int r, int v[]) {

    if (p < r) {

        if (v[p] < v[r]) {
            int temp = v[p];
            v[p] = v[r];
            v[r] = temp;
        }

        int piv1 = v[p];
        int piv2 = v[r];

        int lt = p + 1;
        int gt = r - 1;
        int i = p + 1;

        while (i <= gt) {
            if (v[i] > piv1) {
                int temp = v[i];
                v[i] = v[lt];
                v[lt] = temp;
                lt++;
                i++;
            } else if (v[i] < piv2) {
                int temp = v[i];
                v[i] = v[gt];
                v[gt] = temp;
                gt--;
            } else {
                i++;
            }
        }

        lt--;
        gt++;
        
        int temp1 = v[p];
        v[p] = v[lt];
        v[lt] = temp1;

        int temp2 = v[r];
        v[r] = v[gt];
        v[gt] = temp2;

        DualPivotQuickSort(p, lt - 1, v);
        DualPivotQuickSort(lt + 1, gt - 1, v);
        DualPivotQuickSort(gt + 1, r, v);
    }
}
*/