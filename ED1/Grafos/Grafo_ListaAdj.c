#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int vertice;
    struct No *prox;
} No;

typedef struct Grafo {
    int numVertices;
    No** listaAdj;
    int ehDirigido;
} Grafo;

Grafo* criarGrafo(int n, int dirigido) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->numVertices = n;
    g->ehDirigido = dirigido;

    g->listaAdj = (No**)malloc(n * sizeof(No*));

    for (int i = 0; i < n; i++) {
        g->listaAdj[i] = NULL;
    }

    return g;
}

No* criarNo(int v) {
    No* novo = (No*)malloc(sizeof(No));
    novo->vertice = v;
    novo->prox = NULL;

    return novo;
}

void inserirAresta(Grafo* g, int origem, int destino) {
    No* novo = criarNo(destino);
    novo->prox = g->listaAdj[origem];
    g->listaAdj[origem] = novo;

    if (g->ehDirigido == 0) {
        No* novoVolta = criarNo(origem);
        novoVolta->prox = g->listaAdj[destino];
        g->listaAdj[destino] = novoVolta;
    }
}

void imprimirGrafo(Grafo* g) {
    printf("Lista de Adjacência:\n");

    for (int i = 0; i < g->numVertices; i++) {
        printf("Vertice %d: ", i);

        No* atual = g->listaAdj[i];
        while (atual != NULL) {
            printf(" -> %d", atual->vertice);
            atual = atual->prox;
        }
        printf(" -> NULL\n");
    }
}

int main() {
    Grafo* meuGrafo = criarGrafo(4, 0);

    // Conexões: A-B, A-C, B-D, C-D
    inserirAresta(meuGrafo, 0, 1);
    inserirAresta(meuGrafo, 0, 2);
    inserirAresta(meuGrafo, 1, 3);
    inserirAresta(meuGrafo, 2, 3);

    imprimirGrafo(meuGrafo);

    return 0;
}
