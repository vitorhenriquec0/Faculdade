#include <stdbool.h>   
#include <stdio.h>   
#include <stdlib.h> 

typedef struct
{
    int valor;
} tipo_dado;
 
typedef struct no
{
    tipo_dado info;
    struct no *esq;
    struct no *dir;
    int altura;    
} no;
 
typedef struct no *tree;

// Cria uma  AVL vazia
tree Definir(void);
 
// Verifica se a árvore é vazia
bool Vazia(tree t);
 
// Define nó raiz (com altura inicializada em 1)
tree Criar_raiz(tipo_dado elem);
 
// Retorna a altura (profundidade) da árvore
int Altura(tree t);
 
// Retorna o número de nós da árvore
int Numero_nos(tree t);
 
// (|altE - altD| <= 1 em todo nó)
bool Balanceada(tree t);
 
// (|nosE - nosD| <= 1 em todo nó)
bool Perf_balanceada(tree t);
 
void Pre_ordem(tree t);
 
void In_ordem(tree t);
 
void Pos_ordem(tree t);
 
// Visita um nó (imprime seu conteúdo)
void Visita(tree t);
 
// Busca recursiva: retorna ponteiro para o nó encontrado, ou NULL
tree Busca_r(tree raiz, tipo_dado elem);
 
// Busca não-recursiva: retorna ponteiro para o nó encontrado, ou NULL
tree Busca_nr(tree raiz, tipo_dado elem);
 

// Retorna a altura armazenada no nó (0 se NULL)
int altura_no(tree n);
 
// Retorna o fator de balanceamento do nó (altura_dir - altura_esq)
int fator_balanceamento(tree n);
 
// Rot. simples à direita
tree rotacao_direita(tree y);
 
// Rot. simples à esquerda
tree rotacao_esquerda(tree x);
 
 
// Busca e insere na AVL mantendo o balanceamento.
// Retorna ponteiro para a raiz da nova AVL.
tree Busca_insere_AVL(tree raiz, tipo_dado elem);
 
// Retorna o menor nó da subárvore (caminha sempre para a esquerda)
tree Busca_menor_a_esquerda(tree node);
 
// Busca e remove na AVL mantendo o balanceamento.
// Retorna ponteiro para a raiz da nova AVL.
tree Busca_remove_AVL(tree raiz, tipo_dado elem);
 
// Libera toda a memória da árvore
void Libera(tree t);