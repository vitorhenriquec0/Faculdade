#include <stdio.h>

int main() {
    
    int vetA[5];
    int vetB[5];
    int aux;
    
    printf("Digite 10 valores:\n");
    for (int i = 0; i < 10; i++) {
        if (i < 5) {
            scanf("%d", &vetA[i]);
        }
        else {
            scanf("%d", &vetB[i - 5]);
        }
    }
    
    printf("Antes da troca:\n");
    printf("A: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", vetA[i]);
    }
    printf("\nB: ");
    for(int i = 0; i < 5; i++) {
        printf("%d ", vetB[i]);
    }
    
    for (int i =0; i < 5; i++) {
        aux = vetA[i];
        vetA[i] = vetB[4 - i];
        vetB[4 - i] = aux;
    }
    
    printf("\n\nDepois da troca:\n");
    printf("A: ");
    for(int i = 0; i < 5; i++) printf("%d ", vetA[i]);
    printf("\nB: ");
    for(int i = 0; i < 5; i++) printf("%d ", vetB[i]);
    
    return 0;
}
