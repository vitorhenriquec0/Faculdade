/*
Com o avanço significativo na pesquisa e nas aplicações de algoritmos de apren-
dizado de máquina e aprendizado profundo, tornou-se essencial o desenvolvimento de
ferramentas mais robustas, capazes de oferecer facilidade e flexibilidade na implemen-
tação de algoritmos e modelos. Nesse contexto, um dos conceitos mais fundamentais
é o dos tensores, que são entidades geométricas generalizadas a partir dos conceitos de
escalares, vetores e matrizes. Eles desempenham um papel crucial na representação e
manipulação de dados complexos em múltiplas dimensões. Especificamente, um escalar
pode ser entendido como um tensor 0D, um vetor como um tensor 1D, e uma matriz
como um tensor 2D. Contudo, também existem tensores de dimensões mais elevadas.
Assim como as matrizes 2D são implementadas na memória RAM, que é linear, os ten-
sores de dimensões mais altas também são armazenados e manipulados nesse mesmo
tipo de memória. Logo, você está encarregado de criar seu primeiro tensor realizando as
seguintes tarefas.

a) Receba da entrada padrão um número inteiro N que indicará a quantidade de elementos
que o tensor armazenará.
b) Receba da entrada padrão um número D que representará a dimensão do tensor.
c) Receba da entrada padrão uma sequência de números n1, n2, . . . , nD que indicará a quanti-
dade de elementos em cada dimensão do tensor.
Note: Existe a seguinte restrição que deverá ser checada ∏dk=1 nk = N. Isto é, a mul-
tiplicação da quantidade de elementos em cada dimensão do tensor deverá ser igual a
quantidade de elementos total no tensor.
d) Receba da entrada padrão os elementos e armazene-os corretamente.
e) Por fim, receba da entrada padrão os números inteiros não negativos i1, i2, . . . , iD que rep-
resentam o índice de cada dimensão e imprima na saída padrão o valor armazenado na
posição T(i1, i2, . . . , iD) do tensor, em que T é o tensor construído nas etapas anteriores.
Note: Os índices iniciam-se do zero.
*/

#include <stdio.h>
#include <stdlib.h>

void alocacao(int **vetor, int n);

int main() {
    int N;
    int D;

    printf("Digite a quantidade de elementos que o tensor armazenará: ");
    scanf("%d", &N);
    
    printf("Digite a quantidade de dimensões que o tensor terá: ");
    scanf("%d", &D);

    int *dim = malloc(D * sizeof(int));
    if (dim == NULL) {
        printf("Erro ao alocar memoria para as dimensoes");
        return 1;
    }

    printf("Digite a quantidade de elementos que cada dimensao do tensor tera: ");
    for (int i = 0; i < D; i++) {
        printf("D[%d]: ", i + 1);
        scanf("%d", *(dim + i));
    }

    int produto = 1;
    for (int i = 0; i < D; i ++) {
        produto *= *(dim + i);
    }

    if (produto != N) {
        printf("Erro: O produto das dimensoes (%d) eh diferente de N (%d)\n", produto, N);
        free(dim);
        return 1;
    }

    int *tensor = malloc(N * sizeof(int));
    if (tensor == NULL) {
        printf("Erro ao alocar memoria para o tensor");
        free(dim);
        return 1;
    }

    printf("\nDigite os elementos do tensor: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", *(tensor + i));
    }

}