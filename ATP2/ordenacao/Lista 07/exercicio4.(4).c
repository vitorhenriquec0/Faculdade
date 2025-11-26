/*
 1.4. Implemente o algoritmo de ordenação SHELLSORT(A) tanto crescente tanto decrescente. Além
 disso, implemente-os usando distintos geradores G(k) dos gaps da sequência, entre eles:

 a) Shell (1959): G(k) = ⌊N/2^k⌋
 b) Hibbard (1963): G(k) = 2k −1
 c) Knuth (1973): G(k) = (3k −1)/2
 ---> d) Sedgewick (1982): G(k) = 4k +3·2k−1 +1
*/

#include <stdio.h>
#include <math.h>

void ShellSortSedgewick(int n, int v[]);

int main() {

    int v[] = {89, 29, 43, 19, 2, 8, 9, 15};
    int n = 8;

    printf("\nVetor nao ordenado: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    ShellSortSedgewick(n, v);

    printf("\n\nVetor ordenado por shell sort sedgewick: ");
    for (int i = 0; i < n; i++) printf("%d ", v[i]);

    return 0;
}

void ShellSortSedgewick(int n, int v[]) {

    int gaps[32];
    int numGaps = 0;

    gaps[numGaps++] = 1;

    int k = 1;
    while (1) {
        // Formula: 4^k + 3 * 2^(k - 1) + 1

        long nextGap = (long)pow(4, k) + 3 * (long)pow(2, k - 1) + 1;

        if (nextGap >= n) break;

        gaps[numGaps++] = (int)nextGap;
        k++;
    }

    for (int g = numGaps - 1; g >= 0; g--) {
        int gap = gaps[g];

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