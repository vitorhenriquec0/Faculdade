#include "AVL.h"

tree Definir(void)
{
    return NULL;
}

bool Vazia(tree t)
{
    return (t == NULL);
}

tree Criar_raiz(tipo_dado elem)
{
    tree raiz = malloc(sizeof(no));
    raiz->info = elem;
    raiz->esq  = NULL;
    raiz->dir  = NULL;
    raiz->altura = 1;   // nó recém-criado sempre tem altura 1
    return raiz;
}

int Altura(tree t)
{
    if (t == NULL)
        return 0;

    int altE = Altura(t->esq);
    int altD = Altura(t->dir);

    return (altE > altD ? altE : altD) + 1;
}

int Numero_nos(tree t)
{
    if (t == NULL)
        return 0;

    return Numero_nos(t->esq) + Numero_nos(t->dir) + 1;
}

bool Balanceada(tree t)
{
    if (t == NULL)
        return true;

    int altE = Altura(t->esq);
    int altD = Altura(t->dir);

    if (abs(altE - altD) > 1)
        return false;

    return Balanceada(t->esq) && Balanceada(t->dir);
}

bool Perf_balanceada(tree t)
{
    if (t == NULL)
        return true;

    int nosE = Numero_nos(t->esq);
    int nosD = Numero_nos(t->dir);

    if (abs(nosE - nosD) > 1)
        return false;

    return Perf_balanceada(t->esq) && Perf_balanceada(t->dir);
}

void Pre_ordem(tree t)
{
    if (t != NULL)
    {
        Visita(t);
        Pre_ordem(t->esq);
        Pre_ordem(t->dir);
    }
}

void In_ordem(tree t)
{
    if (t != NULL)
    {
        In_ordem(t->esq);
        Visita(t);
        In_ordem(t->dir);
    }
}

void Pos_ordem(tree t)
{
    if (t != NULL)
    {
        Pos_ordem(t->esq);
        Pos_ordem(t->dir);
        Visita(t);
    }
}

void Visita(tree t)
{
    printf("Valor: %d  (altura do no: %d)\n", t->info.valor, t->altura);
}


// busca recursiva
tree Busca_r(tree raiz, tipo_dado elem)
{
    if (raiz == NULL)
        return NULL;

    if (elem.valor == raiz->info.valor)
        return raiz;

    if (elem.valor < raiz->info.valor)
        return Busca_r(raiz->esq, elem);
    else
        return Busca_r(raiz->dir, elem);
}

// busca iterativa
tree Busca_nr(tree raiz, tipo_dado elem)
{
    tree p = raiz;

    while (p != NULL)
    {
        if (p->info.valor == elem.valor)
            return p;
        else if (elem.valor > p->info.valor)
            p = p->dir;
        else
            p = p->esq;
    }

    return NULL;
}


// Retorna a altura armazenada no campo do nó (0 se NULL)
int altura_no(tree n)
{
    if (n == NULL) return 0;
    return n->altura;
}

// fb = altura_dir - altura_esq
// se negativo pesou para esquerda, se positivo pesou para direita 
int fator_balanceamento(tree n)
{
    if (n == NULL) return 0;
    return altura_no(n->dir) - altura_no(n->esq);
}

tree rotacao_direita(tree y)
{
    tree x  = y->esq;
    tree T2 = x->dir;

    // realiza a rotação
    x->dir = y;
    y->esq = T2;

    // atualiza alturas (y primeiro, pois agora é filho de x)
    y->altura = (altura_no(y->esq) > altura_no(y->dir) ? altura_no(y->esq) : altura_no(y->dir)) + 1;
    x->altura = (altura_no(x->esq) > altura_no(x->dir) ? altura_no(x->esq) : altura_no(x->dir)) + 1;

    return x; // x é a nova raiz
}

tree rotacao_esquerda(tree x)
{
    tree y  = x->dir;
    tree T2 = y->esq;

    // realiza a rotação
    y->esq = x;
    x->dir = T2;

    // atualiza alturas (x primeiro, pois agora é filho de y)
    x->altura = (altura_no(x->esq) > altura_no(x->dir) ? altura_no(x->esq) : altura_no(x->dir)) + 1;
    y->altura = (altura_no(y->esq) > altura_no(y->dir) ? altura_no(y->esq) : altura_no(y->dir)) + 1;

    return y; // y é a nova raiz
}

tree Busca_insere_AVL(tree raiz, tipo_dado elem)
{
    //inserção normal de ABB
    if (raiz == NULL)
        return Criar_raiz(elem);

    if (elem.valor < raiz->info.valor)
        raiz->esq = Busca_insere_AVL(raiz->esq, elem);
    else if (elem.valor > raiz->info.valor)
        raiz->dir = Busca_insere_AVL(raiz->dir, elem);
    else
    {
        printf("Chave %d ja existe\n", elem.valor);
        return raiz; // chave duplicada: não insere
    }

    //atualiza altura deste ancestral 
    raiz->altura = 1 + (altura_no(raiz->esq) > altura_no(raiz->dir)
                        ? altura_no(raiz->esq) : altura_no(raiz->dir));

    //verifica balanceamento e rotaciona se necessário
    int fb = fator_balanceamento(raiz);

    // pesou à esquerda e o filho esquerdo também
    if (fb < -1 && elem.valor < raiz->esq->info.valor)
        return rotacao_direita(raiz);

    // pesou à direita e o filho direito também
    if (fb > 1 && elem.valor > raiz->dir->info.valor)
        return rotacao_esquerda(raiz);

    //  pesou à esquerda mas o filho esquerdo pesou à direita 
    if (fb < -1 && elem.valor > raiz->esq->info.valor)
    {
        raiz->esq = rotacao_esquerda(raiz->esq); // 1º gira o filho
        return rotacao_direita(raiz);             // 2º gira o pai
    }

    // pesou à direita mas o filho direito pesou à esquerda 
    if (fb > 1 && elem.valor < raiz->dir->info.valor)
    {
        raiz->dir = rotacao_direita(raiz->dir);  // 1º gira o filho
        return rotacao_esquerda(raiz);            // 2º gira o pai
    }

    return raiz;
}

tree Busca_menor_a_esquerda(tree node)
{
    tree p = node;
    while (p != NULL && p->esq != NULL)
        p = p->esq;
    return p;
}

tree Busca_remove_AVL(tree raiz, tipo_dado elem)
{
    // remoção normal de ABB
    if (raiz == NULL)
        return NULL;

    if (elem.valor < raiz->info.valor)
        raiz->esq = Busca_remove_AVL(raiz->esq, elem);
    else if (elem.valor > raiz->info.valor)
        raiz->dir = Busca_remove_AVL(raiz->dir, elem);
    else
    {
        // verifica os casos de remoção

        if (raiz->esq == NULL || raiz->dir == NULL)
        {
            tree temp = raiz->esq ? raiz->esq : raiz->dir;

            if (temp == NULL)
            {
                // caso nó folha, apenas remove
                free(raiz);
                raiz = NULL;
            }
            else
            {
                // caso um unico filho, copia o único filho para o lugar do nó
                *raiz = *temp;
                free(temp);
            }
        }
        else
        {
            // caso  dois filho, encontra o sucessor menor da subárvore direita (mas poderiamos colocar maior da subárvore esquerda)
            tree temp = Busca_menor_a_esquerda(raiz->dir);

            raiz->info = temp->info; // copia o valor do sucessor

            // Remove o sucessor da subárvore direita
            raiz->dir = Busca_remove_AVL(raiz->dir, temp->info);
        }
    }

    // se a árvore ficou vazia após a remoção, encerra
    if (raiz == NULL)
        return NULL;

    //  atualiza altura na volta da recursão
    raiz->altura = 1 + (altura_no(raiz->esq) > altura_no(raiz->dir)
                        ? altura_no(raiz->esq) : altura_no(raiz->dir));

    //  verifica balanceamento e rotaciona (fb do filho para decidir o tipo de rotação)
    int fb = fator_balanceamento(raiz);

    // pesou à esquerda e o filho esquerdo não pesou à direita
    if (fb < -1 && fator_balanceamento(raiz->esq) <= 0)
        return rotacao_direita(raiz);

    // pesou à direita e o filho direito não pesou à esquerda
    if (fb > 1 && fator_balanceamento(raiz->dir) >= 0)
        return rotacao_esquerda(raiz);

    // pesou à esquerda mas o filho esquerdo pesou à direita
    if (fb < -1 && fator_balanceamento(raiz->esq) > 0)
    {
        raiz->esq = rotacao_esquerda(raiz->esq);
        return rotacao_direita(raiz);
    }

    // pesou à direita mas o filho direito pesou à esquerdo
    if (fb > 1 && fator_balanceamento(raiz->dir) < 0)
    {
        raiz->dir = rotacao_direita(raiz->dir);
        return rotacao_esquerda(raiz);
    }

    return raiz;
}

void Libera(tree t)
{
    if (t == NULL)
        return;

    Libera(t->esq);
    Libera(t->dir);
    free(t);
}