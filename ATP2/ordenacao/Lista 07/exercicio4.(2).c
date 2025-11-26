/*
 1.4. Implemente o algoritmo de ordenação SHELLSORT(A) tanto crescente tanto decrescente. Além
 disso, implemente-os usando distintos geradores G(k) dos gaps da sequência, entre eles:

 a) Shell (1959): G(k) = ⌊N/2^k⌋
 ---> b) Hibbard (1963): G(k) = 2k −1
 c) Knuth (1973): G(k) = (3k −1)/2
 d) Sedgewick (1982): G(k) = 4k +3·2k−1 +1
*/

#include <stdio.h>

void ShellSortHibbard(int n, int v[]);

int main() {

    int v[] = {89, 29, 43, 19, 2, 8, 9, 15};
    int n = 8;

    printf("\nVetor nao ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    ShellSortHibbard(n, v);

    printf("\n\nVetor ordenado por shell sort hibbard: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    return 0;

}

void ShellSortHibbard(int n, int v[]) {

    int gapInicial = 1;
    while (gapInicial < n) gapInicial = gapInicial * 2 + 1;
    gapInicial /= 2;

    for (int gap = gapInicial; gap > 0; gap /= 2) {

        for (int i = gap; i < n; i++) {

            int temp = v[i];
            int j;

            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }

            v[j] = temp;
        }
    }
}