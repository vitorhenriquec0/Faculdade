#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int idPagina;
    struct No* prox;
} No;

typedef struct Pilha {
    No* topo;
} Pilha;

Pilha* criarPilha() {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;

    return p;
}

int pilhaVazia(Pilha* p) {
    return (p->topo == NULL);
}

void push(Pilha* p, int pagina) {
    No* novo = (No*) malloc(sizeof(No));
    novo->idPagina = pagina;

    novo->prox = p->topo;
    p->topo = novo;
}

int pop(Pilha* p) {
    if (pilhaVazia(p)) return -1;

    No* lixo = p->topo;
    int paginaRetornada = lixo->idPagina;

    p->topo = p->topo->prox;
    free(lixo);

    return paginaRetornada;
}

void esvaziarPilha(Pilha* p) {
    while (!pilhaVazia(p)) {
        pop(p);
    }
}

typedef struct Navegador {
    int paginaAtual;
    Pilha* pilhaVoltar;
    Pilha* pilhaAvancar;
} Navegador;

Navegador* criarNavegador(int paginaInicial) {
    Navegador* nav = (Navegador*) malloc(sizeof(Navegador));
    nav->paginaAtual = paginaInicial;
    nav->pilhaVoltar = criarPilha();
    nav->pilhaAvancar = criarPilha();

    return nav;
}

void acessarNovaPagina(Navegador* nav, int novaPagina) {
    // joga a pag. que estava na pilha VOLTAR
    push(nav->pilhaVoltar, nav->paginaAtual);

    // atualiza a tela para a nova pagina
    nav->paginaAtual = novaPagina;

    // se navegou p frente, o que estava antes sai
    // AVANÇAR é esvaziado
    esvaziarPilha(nav->pilhaAvancar);

    printf("Acessou nova pagina: %d\n", novaPagina);
}

void voltarPagina(Navegador* nav) {
    if (pilhaVazia(nav->pilhaVoltar)) {
        printf("Nao ha paginas no historico para voltar.\n");
        return;
    }

    // pagina atual é jogada na pilha AVANÇAR (caso me arrependa)
    push(nav->pilhaAvancar, nav->paginaAtual);

    // pego a pagina do topo do VOLTAR e defino como atual
    nav->paginaAtual = pop(nav->pilhaVoltar);

    printf("Voltou para a pagina: %d\n", nav->paginaAtual);
}

void avancarPagina(Navegador* nav) {
    if (pilhaVazia(nav->pilhaAvancar)) {
        printf("Nao ha paginas para avancar.\n");
        return;
    }

    // jogo a pagina atual para a pilha de VOLTAR
    push(nav->pilhaVoltar, nav->paginaAtual);

    // pego a pagina do topo do AVANÇAR e defino como atual
    nav->paginaAtual = pop(nav->pilhaAvancar);

    printf("Avancou para a pagina: %d\n", nav->paginaAtual);
}

int main() {
    Navegador* chrome = criarNavegador(10); 
    printf("Pagina atual inicial: %d\n\n", chrome->paginaAtual);

    acessarNovaPagina(chrome, 20); // Clicou em um vídeo no YouTube
    acessarNovaPagina(chrome, 30); // Clicou no link pro GitHub
    printf("-> Agora na pagina: %d\n\n", chrome->paginaAtual);

    voltarPagina(chrome); // Deve voltar pro YouTube (20)
    voltarPagina(chrome); // Deve voltar pro Google (10)
    // Tentar voltar antes de existir internet (Pilha vazia):
    voltarPagina(chrome); 
    
    avancarPagina(chrome); // Deve ir pro YouTube (20) de novo
    
    // esta no YouTube (20). O GitHub (30) está na pilha de Avançar.
    // Mas agora vamos clicar em um link NOVO (StackOverflow - 40).
    // A regra diz que o futuro antigo (GitHub) deve ser apagado!
    acessarNovaPagina(chrome, 40); 
    
    // Como acessamos uma página nova, não existe mais futuro para avançar
    avancarPagina(chrome); 

    return 0;
}