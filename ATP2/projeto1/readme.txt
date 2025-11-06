==========================================================
 README - Projeto 1 - mEditor
 Algoritmos e Técnicas de Programação II
 Aluno: Vítor Henrique Cardoso
==========================================================

-> DESCRIÇÃO
O mEditor é um editor de texto simples desenvolvido em linguagem C.
Ele permite criar, editar e manipular documentos .txt e .bin compostos por várias linhas de texto, com suporte a inserção, remoção, substituição, concatenação, divisão e junção de linhas, além das funções de desfazer (undo) e refazer (redo).

-> COMPILAÇÃO
 	Para compilar o projeto, utilize o GCC:

 		gcc -Wall -Wextra -g main.c editor.c stack.c undo.c -o mEditor

 	Sendo que:
 	-Wall ------> mostra avisos básicos do compilador.
 	-Wextra ----> mostra avisos adicionais para boas práticas
 	-g ---------> inclui informações de depuração
 	-o mEditor -> define o nome do executável gerado

 	Ou, se houver um Makefile, basta executar:

		make

-> EXECUÇÃO
	Após compilar, execute o programa:

 		./mEditor
 
 	O programa abrirá um prompt interativo no terminal:
 
 		Bem vindo ao mEditor!
 		mtext>

-> COMANDOS DISPONÍVEIS
 	open <arquivo> ---------> Abre um arquivo texto e carrega no editor. Cria o arquivo caso não exista.
 	openbin <arquivo> ------> Abre um arquivo salvo em formato binário.
 	save <arquivo> ---------> Salva o documento atual em formato (.txt).
 	savebin <arquivo> ------> Salva o documento em formato binário (.bin).
 	print ------------------> Exibe todas as linhas de forma numerada (implementado com recursão).
 	i <pos> <texto> --------> Insere uma nova linha antes da posição <pos>.
 	d <pos> ----------------> Remove a linha na posição indicada.
 	r <pos> <novo texto> ---> Substitui o conteúdo da linha.
 	a <pos> <sufixo> -------> Concatena um sufixo ao final da linha.
 	split <pos> <idx> ------> Divide a linha <pos> em duas partes no índice <idx>
 	join <pos> -------------> Une a linha <pos> com a linha seguinte.
 	undo -------------------> Desfaz a última operação.
 	redo -------------------> Refaza última operação desfeita.
 	quit -------------------> Encerra o programa, liberando toda a memória alocada.

-> OBSERVAÇÕES
	- As operações são armazenadas em pilhas (undo/redo).
	- O print e o salvamento usam recursão.
	- O código está dividido em módulos (.c e .h).