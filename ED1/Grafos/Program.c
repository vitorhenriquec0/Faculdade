// testando um grafo com matriz de adjacência

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10

typedef struct Grafo {
    int numVertices;
    int matriz[MAX_VERTICES][MAX_VERTICES];
    int ehDirigido;
    int ehPonderado;
} Grafo;

Grafo* criarGrafo(int n, int dirigido, int ponderado) {
    Grafo *g = (Grafo*)malloc(sizeof(Grafo));
    g->numVertices = n;
    g->ehDirigido = dirigido;
    g->ehPonderado = ponderado;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            g->matriz[i][j] = 0;
        }
    }

    return g;
}

void inserirAresta(Grafo* g, int origem, int destino, int peso) {
    if (origem < 0 || origem >= g->numVertices || destino < 0 || destino >= g->numVertices) {
        printf("Vertice invalido.\n");
        return;
    }

    int valor = (g->ehDirigido) ? peso : 1;
    g->matriz[origem][destino] = valor;

    if (g->ehDirigido == 0) {
        g->matriz[destino][origem] = valor;
    }
}

void imprimirMatriz(Grafo* g) {
    for (int i = 0; i < g->numVertices; i++) {
        printf("%d ", i);
    }
    printf("\n");

    for (int i = 0; i < g->numVertices; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->numVertices; j++) {
            printf("%d ", g->matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int numVertices = 4;
    int ehDirigido = 1;
    
    Grafo* grafo = criarGrafo(numVertices, ehDirigido, 1);

    inserirAresta(grafo, 0, 1, 1);
    inserirAresta(grafo, 0, 2, 1);
    inserirAresta(grafo, 1, 3, 1);
    inserirAresta(grafo, 2, 3, 1);

    imprimirMatriz(grafo);

    return 0;
}