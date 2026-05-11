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

tree Definir(void);
 
bool Vazia(tree t);
 
// Define nó raiz (com altura inicializada em 1)
tree Criar_raiz(tipo_dado elem);
 
int Altura(tree t);
 
int Numero_nos(tree t);
 
// (|altE - altD| <= 1 em todo nó)
bool Balanceada(tree t);
 
// (|nosE - nosD| <= 1 em todo nó)
bool Perf_balanceada(tree t);
 
void Pre_ordem(tree t);
 
void In_ordem(tree t);
 
void Pos_ordem(tree t);
 
void Visita(tree t);
 
tree Busca_r(tree raiz, tipo_dado elem);
 
tree Busca_nr(tree raiz, tipo_dado elem);
 
// Retorna a altura armazenada no nó (0 se NULL)
int altura_no(tree n);
 
// (altura_dir - altura_esq)
int fator_balanceamento(tree n);
 
tree rotacao_direita(tree y);
 
tree rotacao_esquerda(tree x);
 
// bbusca e insere na avl mantendo o balanceamento
// retorna ponteiro para a raiz da nova avl
tree Busca_insere_AVL(tree raiz, tipo_dado elem);
 
tree Busca_menor_a_esquerda(tree node);
 
// busca e remove na avlmantendo o balanceamento
// retorna ponteiro para a raiz da nova avl
tree Busca_remove_AVL(tree raiz, tipo_dado elem);
 
void Libera(tree t);