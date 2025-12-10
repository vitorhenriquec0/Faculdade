#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

No* criarNo(int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) {
        return;
    }

    imprimirEmOrdem(raiz->esq);

    printf("%d ", raiz->valor);

    imprimirEmOrdem(raiz->dir);
}

int main() {
    No* raiz = criarNo(10);
    No* filho1 = criarNo(5);
    No* filho2 = criarNo(15);

    raiz->esq = filho1;
    raiz->dir = filho2;

    imprimirEmOrdem(raiz);

    return 0;
}