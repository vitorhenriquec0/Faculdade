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

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return criarNo(valor);

    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) return;

    imprimirEmOrdem(raiz->esq);

    printf("%d ", raiz->valor);

    imprimirEmOrdem(raiz->dir);
}

void limpar(No* raiz) {
    if (raiz == NULL) return;

    limpar(raiz->esq);
    limpar(raiz->dir);

    printf("Limpando: %d\n", raiz->valor);
    free(raiz);
}

int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 10); 
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 18);

    printf("Arvore: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    limpar(raiz);

    return 0;
}