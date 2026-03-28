#include <stdlib.h>
#include <stdio.h>
#include "arvoreB.h"

int main (){
	tree t;
	Definir(&t);
	
	tipo_dado d;
	
	d.valor = 4;
	t = criaRaiz(t, d);
	
	//Filhos do 4
	d.valor = 2;
	insereEsquerda(t, d);
	d.valor = 6;
	insereDireita(t, d);
	
	//Filhos do 2
	d.valor = 1;
	insereEsquerda(t->esq, d);
	d.valor = 3;
	insereDireita(t->esq, d);
	
	//Filhos do 6
	//d.valor = 5;
	//insereEsquerda(t->dir, d);
	//d.valor = 7;
	//insereDireita(t->dir, d);
		
	//Filho do 5 direita
	//d.valor = 8;
	//insereDireita(t->dir->esq, d);
    //Filho do 8 esquerda
	//d.valor = 10;
	//insereEsquerda(t->dir->esq->dir, d);
	
	printf("Altura: %d\n", Altura(t));
	printf("Nro nos: %d\n", numeroNos(t));
	
	//printf("\n\n Pre Ordem \n");	
	//preOrdem(t);
	
	//printf("\n\n Em Ordem \n");	
	//inOrdem(t);
	
	//printf("\n\n P�s Ordem \n");	
	//posOrdem(t);
	
	//Realizar o mesmo exerc�cio de visualiza��o com buscaElemento e Balanceada
	//if (buscaElemento(t, d))
	//	printf("Existe o elemento");
	//else
	//	printf("Nao existe o elemento");
	
	if (Balanceada(t))
		printf("Eh balanceada");
	else
		printf("Nao � balanceada");
			
	return 0;
}
