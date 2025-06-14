/* Ler dois vetores A e B de mesmo tamanho M (inteiros).
Criar um terceiro vetor C que seja a inversão de A
(o primeiro elemento de A se torna o último de C,
o segundo de A se torna o penúltimo de C, e assim por diante).
Em seguida, verificar e informar quantos elementos de B são iguais
aos elementos correspondentes (mesma posição) em C.*/

#include <stdio.h>

#define m 5

int main () {
    
    int vetA[m], vetB[m], vetC[m];
    int elementosIguais = 0;
    
    printf("\nPreencha o vetor A: \n");
    for (int i = 0; i < m; i++) {
        printf("Elemento [%d] do vetor A: ", i);
        scanf("%d", &vetA[i]);
    }
    
    printf("\nPreencha o vetor B: \n");
    for (int i = 0; i < m; i++) {
        printf("Elemento [%d] do vetor B: ", i);
        scanf("%d", &vetB[i]);
    }
    
    for (int i = 0; i < m; i++) {
        vetC[i] = vetA[m - 1 - i];
    }
    
    for (int i = 0; i < m; i++) {
        if (vetB[i] == vetC[i]) {
            elementosIguais++;
        }
    }
    
    printf("O vetor B e vetor C possuem %d elementos correspondentes iguais",
            elementosIguais);
    
    return 0;
}
