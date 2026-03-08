#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct no* prox;
} No;

typedef struct Conjunto {
    No* inicio;
} Conjunto;


Conjunto* criarConjuntoVazio() {
    Conjunto* A = (Conjunto*) malloc(sizeof(Conjunto));
    A->inicio = NULL;
    return A;
}

int Membro(int x, Conjunto* A) {
    if (A == NULL || A->inicio == NULL) return 0;

    No* atual = A->inicio;

    while (atual  != NULL) {
        if (atual->valor == x) {
            return 1; // achou = retorna verdadeiro
        }
        atual = atual->prox;
    }
    return 0; // chegou ao fim e nao achou
}

void Insere(int x, Conjunto* A) {

    if (Membro(x, A) == 1) return; // membro já existe

    No* novo = (No*) malloc(sizeof(No));
    novo->valor = x;

    // insere no inicio da lista (mais rapido O(1))
    novo->prox = A->inicio;
    A->inicio = novo;
}

int Igual(Conjunto* A, Conjunto* B) {
    if (A == NULL || B == NULL) return;

    No* atualA = A->inicio;
    No* atualB = B->inicio;

    while (atualA != NULL && atualB != NULL) {
        atualA = atualA->prox;
        atualB = atualB->prox;
    }

    if (atualA != NULL || atualB!= NULL) return 0;

    atualA = A->inicio;
    while (atualA != NULL) {
        if (Membro(atualA->valor, B) == 0) return 0;

        atualA = atualA->prox;
    }
    
    return 1;
}

void Uniao(Conjunto* A, Conjunto* B, Conjunto* C) {
    if (A == NULL || B == NULL || C == NULL) return;

    No* atualA = A->inicio;
    while (atualA != NULL) {
        Insere(atualA->valor, C);

        atualA = atualA->prox;
    }

    No* atualB = B->inicio;
    while (atualB != NULL) {
        Insere(atualB->valor, C);

        atualB = atualB->prox;
    }
}

void Interseccao(Conjunto* A, Conjunto* B, Conjunto* C) {
    if (A == NULL || B == NULL || C == NULL) return;

    No* atualA = A->inicio;
    while (atualA != NULL) {
        if (Membro(atualA->valor, B) == 1) {
            Insere(atualA->valor, C);
        }
        atualA = atualA->prox;
    }
}

void ImprimirConjunto(Conjunto* A, char* nome) {
    printf("Conjunto %s: { ", nome);
    if (A != NULL) {
        No* atual = A->inicio;
        while (atual != NULL) {
            printf("%d ", atual->valor);
            atual = atual->prox;
        }
    }
    printf("}\n");
}

int main() {
    Conjunto* A = criarConjuntoVazio();
    Conjunto* B = criarConjuntoVazio();
    Conjunto* C_Uniao = criarConjuntoVazio();
    Conjunto* D_Inter = criarConjuntoVazio();

    Insere(10, A);
    Insere(20, A);
    Insere(30, A);
    Insere(20, A); // valor repetido: deve ser ignorado

    Insere(30, B);
    Insere(40, B);
    Insere(50, B);

    printf("--- CONJUNTOS ORIGINAIS ---\n");
    ImprimirConjunto(A, "A");
    ImprimirConjunto(B, "B");

    printf("\n--- TESTE DE IGUALDADE ---\n");
    if (Igual(A, B)) {
        printf("A e B sao IGUAIS\n");
    } else {
        printf("A e B sao DIFERENTES\n");
    }

    printf("\n--- TESTE DE UNIAO ---\n");
    Uniao(A, B, C_Uniao);
    ImprimirConjunto(C_Uniao, "Uniao (A U B)");

    printf("\n--- TESTE DE INTERSECCAO ---\n");
    Interseccao(A, B, D_Inter);
    ImprimirConjunto(D_Inter, "Interseccao (A inter B)");

    return 0;
}