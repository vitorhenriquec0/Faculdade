/*
1.8. Para todos os exercícios de implementação de algoritmos de ordenação de vetores
anteriormente mencionados, adapte-os para listas simplesmente ligadas.

SELECTION SORT

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
    for (No* p = lista; p!= NULL; p = p->proximo) {
        printf("%d ", p->valor);
    }
    printf("\n");
}

void SelectionSortLista(No* lista);

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
    
    SelectionSortLista(lista);
    
    printf("Lista ordenada: ");
    imprime(lista);
    
    return 0;
}

void SelectionSortLista(No* lista) {
    if (lista == NULL || lista->proximo == NULL) {
        return;
    }

    for (No* i = lista; i != NULL; i = i->proximo) {
        No* min = i;

        for (No* j = i->proximo; j != NULL; j = j->proximo) {
            if (j->valor < min->valor) {
                min = j;
            }
        }

        int temp = i->valor;
        i->valor = min->valor;
        min->valor = temp;
    }
}