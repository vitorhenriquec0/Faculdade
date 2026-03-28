#include <stdio.h>
#include <stdlib.h>
#include "arvoreB.h"

// Implementações
// ---------------------------------------

// Cria AB vazia
void Definir (tree *t){
	*t = NULL;
}

// Verifica se a AB esta vazia
bool Vazia (tree t){
	if(t == NULL){
		return (true);
	}
	return (false);
}

// Define o nó raiz
tree criaRaiz (tree t, tipo_dado elem){
	t = malloc (sizeof (no));
	
	if(!t){
		printf("Nao foi possivel criar o no raiz.\n");
		exit(1);
	}
	
	t->info = elem;
	t->dir = NULL;
	t->esq = NULL;
	
	return(t);		

}

//Retorna a altura (profundidade) da AB
int Altura (tree t){
	
	if (Vazia(t)){
		printf("Vazio\n");
		return 0;
	}
	
	if (t->esq != NULL)
		printf("No corrente: %d; e chama esquerda: %d\n", t->info.valor, t->esq->info.valor);
	int altE = Altura (t->esq);
	
	if (t->dir != NULL)
		printf("No corrente: %d; e chama direita: %d\n", t->info.valor, t->dir->info.valor);
	int altD = Altura (t->dir);

	if (altE > altD){
		return (altE + 1);
	}
	return (altD + 1); 
	//altura = max(altE, altD) + 1
}

bool Balanceada (tree t){
	if (Vazia (t)) return true;
	
	else if (t->esq == NULL && t->dir == NULL) // se n�o tem filhos
		return true;
		
	else if (t->esq != NULL && t->dir != NULL) //se tem duas sub-�rvores
		return (Balanceada(t->esq) && Balanceada(t->dir) && abs(Altura(t->esq) - Altura(t->dir)) <= 1);
		
	else if (t->esq != NULL) //Se tem um unico filho na esquerda
		return (Altura(t->esq) == 1);
		
	else return (Altura(t->dir) == 1);//Se tem um unico filho na direita
}

int numeroNos(tree t){
	
	if (Vazia (t)) 
		return 0;
	
	int nEsq = numeroNos (t->esq);
	int nDir = numeroNos (t->dir);

	return (nDir + nEsq + 1);
}


bool perfeitamenteBalanceada (tree t){
	if (Vazia (t)) return true;
	
	else if (t->esq == NULL && t->dir == NULL)
		return true;
		
	else if (t->esq != NULL && t->dir != NULL)
		return (perfeitamenteBalanceada(t->esq) && perfeitamenteBalanceada(t->dir) && abs(numeroNos(t->esq) - numeroNos(t->dir)) <= 1);
		//para ser perfeitamente balanceada o n�mero de n�s pode diferir em, no m�ximo, 1
	else if (t->esq != NULL)  
		return (numeroNos (t->esq) == 1);
		
	else return (numeroNos (t->dir) == 1);
}

bool insereDireita (tree pai, tipo_dado elem){
	if (Vazia (pai)){
		return false;
	}
	if (pai->dir != NULL){
		printf("Ja possui filho a direita. \n");
		return false;
	}
	pai->dir = malloc (sizeof (struct no));
	if(!pai->dir){
		printf("Nao foi possivel criar o no.\n");
		exit(1);
	}
	pai->dir->info = elem;
	pai->dir->dir = NULL;
	pai->dir->esq = NULL;

	return true;
}

bool insereEsquerda (tree pai, tipo_dado elem){
	if (Vazia (pai)){
		return false;
	}
	if (pai->esq != NULL){
		printf("Ja possui filho a esquerda. \n");
		return false;
	}
	
	pai->esq = malloc (sizeof (struct no));
	if(!pai->esq){
		printf("Nao foi possivel criar o no.\n");
		exit(1);
	}
	pai->esq->info = elem;
	pai->esq->dir = NULL;
	pai->esq->esq = NULL;
	return (true);
}

void Visita (tree t){
	printf("Valor: %d\n", t->info.valor);
}

void preOrdem (tree t){
	if(t != NULL){
		Visita (t);
		preOrdem (t->esq);
		preOrdem (t->dir);
	}	
}

void inOrdem (tree t){
	if(t != NULL){
		inOrdem (t->esq);
		Visita (t);
		inOrdem (t->dir);
	}	
}

void posOrdem (tree t){
	if(t != NULL){
		posOrdem (t->esq);
		posOrdem (t->dir);
		Visita (t);
	}

}

bool buscaElemento(tree t, tipo_dado elem) {
    // Caso base: se a raiz � nula, retorna falso
    if (t == NULL)
        return false;
    
    // Se a chave est� na raiz atual, retorna verdadeiro
    if (t->info.valor == elem.valor)
        return true;
        
    // Caso contr�rio, busca recursivamente nas sub�rvores esquerda e direita
    return buscaElemento(t->esq, elem) || buscaElemento(t->dir, elem);
}

int pertence (tree t, tipo_dado elem) {
	
	if (Vazia(t))
		return 0; //�rvore vazia
	else
		return t->info.valor == elem.valor || pertence (t->esq,elem) || pertence (t->dir,elem);
}
//--
//---------------------------------------

