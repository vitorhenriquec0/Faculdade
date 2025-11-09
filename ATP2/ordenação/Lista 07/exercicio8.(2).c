/*
1.8. Para todos os exercícios de implementação de algoritmos de ordenação de vetores
anteriormente mencionados, adapte-os para listas simplesmente ligadas.

INSERTION SORT

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

No* insere(No* lista, int valor) {
    No* novo = malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = lista;

    return novo;
}

void imprime(No* lista) {
    for (No* p = lista; p != NULL; p = p->proximo) {
        printf("%d ", p->valor);
    }
    printf("\n");
}

No* InsertionSortLista(No* lista);

int main() {
    No* lista = NULL;
    lista = insere(lista, 15);
    lista = insere(lista, 9);
    lista = insere(lista, 8);
    lista = insere(lista, 2);
    lista = insere(lista, 19);
    lista = insere(lista, 43);
    
    printf("Lista original: ");
    imprime(lista);
    
    lista = InsertionSortLista(lista);
    
    printf("Lista ordenada: ");
    imprime(lista);
    
    return 0;
}

No* InsertionSortLista(No* lista) {
    if (lista == NULL || lista->proximo == NULL) return lista;

    No* listaOrdenada = NULL;
    No* atual = lista;

    while (atual != NULL) {

        No* proximo = atual->proximo;

        if (listaOrdenada == NULL || atual->valor < listaOrdenada->valor) {
            atual->proximo = listaOrdenada;
            listaOrdenada = atual;
        } else {
            No* p = listaOrdenada;

            while (p->proximo != NULL && p->proximo->valor < atual->valor) {
                p = p->proximo;
            }

            atual->proximo = p->proximo;
            p->proximo = atual;
        }

        atual = proximo;

    }

    return listaOrdenada;
}

/*
No* InsertionSortLista(No* lista) {
    if (lista == NULL || lista->proximo == NULL) return lista;

    No* listaOrdenada = NULL;
    No* atual = lista;

    while (atual != NULL) {

        No* proximo = atual->proximo;

        if (listaOrdenada == NULL || atual->valor > listaOrdenada->valor) {
            atual->proximo = listaOrdenada;
            listaOrdenada = atual;
        } else {
            No* p = listaOrdenada;

            while (p->proximo != NULL && p->proximo->valor > atual->valor) {
                p = p->proximo;
            }

            atual->proximo = p->proximo;
            p->proximo = atual;
        }

        atual = proximo;

    }

    return listaOrdenada;
}
*/