/*
Remoção ==> Problema estrutural: se tirar um nó no meio da árvore
ele quebra em duas partes. É preciso emendar os pedaços sem quebrar
a regra "Esquerda < Pai < Direita"

Casos possíveis:
  1) O nó é uma folha (sem filhos): É só apagar, nao tem ninguem pendurado

  2) O nó tem 1 filho: É só pular o nó que vai ser romovido
  e ligar o pai dele direto no filho

  3) O nó tem 2 filhos: Para substituir um nó com 2 filhos é preciso pegar o
  valor mais próximo dele. Geralmente é pego o menor valor da subárvore da direita (o sucessor)

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *esq;
    struct No *dir;
} No;

// Função auxiliar pra encontrar o menor valor de uma subárvore
No* encontrarMinimo(No* atual) {
    while (atual->esq != NULL) {
        atual = atual->esq;
    }
    return atual;
}

No* remover(No* raiz, int valor) {

    if (raiz == NULL) return NULL; // nao encontrado

    // a busca é identida à função inserir
    if (valor < raiz->valor) {
        raiz->esq = remover(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = remover(raiz->dir, valor);
    } else {
        // achou!

        // caso o nó tenha 0 ou 1 filho
        if (raiz->esq == NULL) {
            No* temp = raiz->dir;
            free(raiz);
            return temp;
        } else if (raiz->dir == NULL) {
            No* temp = raiz->esq;
            free(raiz);
            return temp;
        }

        // caso o nó tenha 2 filhos
        // nao removemos o nó, mas trocamos o seu valor

        //encontrar o menor valor do lado direito (sucessor)
        No* temp = encontrarMinimo(raiz->dir);

        // copiar o valor do sucessor pro nó atual
        raiz->valor = temp->valor;

        //remover o sucessor original (duplicado)
        raiz->dir = remover(raiz->dir, temp->valor);
    }

    return raiz;
}

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

    free(raiz);
}

int main() {
    No* raiz = NULL;

    raiz = inserir(raiz, 10); 
    raiz = inserir(raiz, 5);
    raiz = inserir(raiz, 15);
    raiz = inserir(raiz, 2);
    raiz = inserir(raiz, 18);

    printf("Arvore Original: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    printf("Removendo o 10\n");
    raiz = remover(raiz, 10);

    printf("Nova Arvore:     ");
    imprimirEmOrdem(raiz);
    printf("\n");

    limpar(raiz);
    return 0;
}