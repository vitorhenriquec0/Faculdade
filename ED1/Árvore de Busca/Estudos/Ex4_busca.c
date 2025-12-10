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
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }

    return raiz;
}

int Busca(No* raiz, int valor) {
    if (raiz == NULL) return 0;

    if (raiz->valor == valor) return 1;

    if (valor < raiz->valor) {
        return Busca(raiz->esq, valor);
    } else {
        return Busca(raiz->dir, valor);
    }
}

void imprimirEmOrdem(No* raiz) {
    if (raiz == NULL) return;

    imprimirEmOrdem(raiz->esq);

    printf("%d ", raiz->valor);

    imprimirEmOrdem(raiz->dir);
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

    if (Busca(raiz, 15)) {
        printf("O numero 15 existe na arvore.\n");
    } else {
        printf("O numero 15 nao existe na arvore.\n");
    }

    return 0;
}