#include <stdlib.h>
#include <stdio.h>

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
    printf("Lista de Adjacencia:\n");

    for (int i = 0; i < g->numVertices; i++) {
        printf("Vertice %d: ", i);

        No* atual = g->listaAdj[i];
        while(atual != NULL) {
            printf(" -> %d", atual->vertice);
            atual = atual->prox;
        }
        printf(" -> NULL\n");
    }
}

void dfs_recursivo(Grafo* g, int u, int* visitados) {
    visitados[u] = 1;
    printf("%d -> ", u);

    No* atual = g->listaAdj[u];
    while(atual != NULL) {
        int vizinho = atual->vertice;
        if (visitados[vizinho] == 0) {
            dfs_recursivo(g, vizinho, visitados);
        }
        atual = atual->prox;
    }
}

void buscaProfundidade(Grafo* g, int inicio) {
    int* visitados = (int*)calloc(g->numVertices, sizeof(int));

    printf("DFS (inicio em %d)\n", inicio);

    dfs_recursivo(g, inicio, visitados);
    free(visitados);
}

int main() {
    Grafo* g = criarGrafo(4, 0);

    inserirAresta(g, 0, 1);
    inserirAresta(g, 0, 2);
    inserirAresta(g, 1, 3);
    inserirAresta(g, 2, 3);

    imprimirGrafo(g);

    buscaProfundidade(g, 0);
}