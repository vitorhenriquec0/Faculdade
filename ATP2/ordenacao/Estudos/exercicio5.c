/*
Insertion Sort adaptado para listas
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int data;
    struct no *prox;
} No;

No* newNode(int data) {
    No* node = malloc(sizeof(No));
    node->data = data;
    node->prox == NULL;
    return node;
}

void insert(No** node, int data) {
    No* new = newNode(data);
    new->prox = *node;
    *node = new; 
}

void print(No* head) {
    No* temp = head;
    while (temp != NULL) {
        printf("[%d] -> ", temp->data);
        temp = temp->prox;
    }
    printf("NULL\n");
}

No* InsertionSortLista(No* head) {
    No* ordenada = NULL;
    No* atual = head;

    while (atual != NULL) {
        No* nextNode = atual->prox;

        if (ordenada == NULL || atual->data < ordenada->data) {
            atual->prox = ordenada;
            ordenada = atual;
        } else {
            No* temp = ordenada;
            while (temp->prox != NULL && temp->prox->data < atual->data) {
                temp = temp->prox;
            } 
            atual->prox = temp->prox;
            temp->prox = atual;
        }
        atual = nextNode;
    }
    return ordenada;
}

int main() {
    No* lista = NULL; // A lista começa vazia!

    // Vamos criar uma lista bagunçada: 20 -> 5 -> 10 -> 2
    // Note que inserindo no início, a ordem de inserção fica invertida visualmente
    insert(&lista, 2);
    insert(&lista, 10);
    insert(&lista, 5);
    insert(&lista, 20);

    printf("Lista Original:\n");
    print(lista);

    // Chamada da ordenação
    lista = InsertionSortLista(lista);

    printf("\nLista Ordenada:\n");
    print(lista);

    return 0;
}