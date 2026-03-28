#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

typedef struct {
    int nos[MAX];
    int tamanho;
} ABC;

void carregarABC(ABC* arvore, int h) {
    if (h <= 0) {
        printf("Erro: altura invalida.\n");
        return;
    }

    int totalNos = pow(2, h) - 1;

    if (totalNos + 1 > MAX) {
        printf("Erro: a altura %d ultrapassa o limite MAX.", h);
        return;
    }

    arvore->tamanho = totalNos;

    printf("Preencha os %d nos da arvore:\n", arvore->tamanho);

    for (int i = 1; i <= totalNos; i++) {
        printf("No [%d]: ", i);
        scanf("%d", &arvore->nos[i]);
    }
}

void preOrdem(ABC* arvore, int i) {
    if (i > arvore->tamanho) return;

    printf("%d ", arvore->nos[i]);
    preOrdem(arvore, 2 * i);
    preOrdem(arvore, 2 * i + 1);
}

void emOrdem(ABC* arvore, int i) {
    if (i > arvore->tamanho) return;

    emOrdem(arvore, 2 * i );
    printf("%d ", arvore->nos[i]);
    emOrdem(arvore, 2 * i + 1);
}

void posOrdem(ABC* arvore, int i) {
    if (i > arvore->tamanho) return;

    posOrdem(arvore, 2 * i);
    posOrdem(arvore, 2 * i + 1);
    printf("%d " , arvore->nos[i]);
}

int main() {
    ABC arvore;
    arvore.tamanho = 0;
    int altura;

    printf("Digite a altura da ABC: ");
    scanf("%d", &altura);

    carregarABC(&arvore, altura);

    preOrdem(&arvore, 1);
    printf("\n");

    emOrdem(&arvore, 1);
    printf("\n");

    posOrdem(&arvore, 1);

    return 0;
}