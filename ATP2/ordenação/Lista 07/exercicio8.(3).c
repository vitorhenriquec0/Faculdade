/*
1.8. Para todos os exercícios de implementação de algoritmos de ordenação de vetores
anteriormente mencionados, adapte-os para listas simplesmente ligadas.

MERGE SORT

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

No* dividirLista(No* head) {
    if (head == NULL || head->proximo == NULL) return NULL;

    No* slow = head;
    No* fast = head->proximo;

    while (fast != NULL && fast->proximo != NULL) {
        slow = slow->proximo;
        fast = fast->proximo->proximo;
    }

    No* meio = slow->proximo;
    slow->proximo = NULL;

    return meio;
}

No* intercalar(No* a, No* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    No* resultado = NULL;

    if (a->valor <= b->valor) {
        resultado = a;
        resultado->proximo = intercalar(a->proximo, b);
    } else {
        resultado = b;
        resultado->proximo = intercalar(a, b->proximo);
    }

    return resultado;
}

No* MergeSort(No* head) {
    if (head == NULL || head->proximo == NULL) return head;

    No* meio = dividirLista(head);
    No* esquerda = MergeSort(head);
    No* direita = MergeSort(meio);

    return intercalar(esquerda, direita);
}

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
    
    lista = MergeSort(lista);
    
    printf("Lista ordenada: ");
    imprime(lista);
    
    return 0;
}

/*

-> DECRESCENTE

No* intercalar(No* a, No* b) {
    if (a == NULL) return b;
    if (b == NULL) return a;

    No* resultado = NULL;

    if (a->valor <= b->valor) {
        resultado = b;
        resultado->proximo = intercalar(a, b->proximo);
    } else {
        resultado = a;
        resultado->proximo = intercalar(a->proximo, b);
    }

    return resultado;
}
*/