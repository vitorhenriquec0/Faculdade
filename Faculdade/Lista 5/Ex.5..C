/* 5. Escreva um programa para simular as operações de uma pilha (First in last out - FILO), com
10 posições. O primeiro elemento a ser empilhado é o último a ser retirado da pilha. Este tipo de
estrutura é comumente utilizado para gerenciar chamadas de funções, por exemplo. O programa
deve ter as operações de inserção e remoção. O processo de remoção não é físico. Uma
remoçãodeve ser controlada por uma indicação lógica. */

#include <stdio.h>

#define tamanhoPilha 10

int main () {
    
    int pilha[tamanhoPilha];
    int topo = -1;
    int opcao, valor;
    
    do {
        
        printf("\n\nPilha atual:");
        if (topo == -1) {
            printf("[Vazia].\n");
        } else {
            for (int i = 0; i <= topo; i++) {
                printf("[%d] ", pilha[i]);
            }
            printf("<- TOPO\n");
        }
        
        printf("\n------------------------\n");
        printf("1. Empilhar (Inserir)\n");
        printf("2. Desempilhar (Remover)\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                if (topo == tamanhoPilha - 1) {
                    printf("Pilha cheia!");
                } else {
                    printf("Digite o valor a ser empilhado:");
                    scanf("%d", &valor);
                    topo++;
                    pilha[topo] = valor;
                    printf("Elemento empilhado com sucesso!");
                }
                break;
                
            case 2:
                if (topo = -1) {
                    printf("Pilha vazia!");
                } else {
                    printf("Elemento %d removido da pilha.\n", pilha[topo]);
                    topo--;
                }
                break;
                
            case 0:
                printf("Encerrando o programa.\n");
                break;
                
            default: printf("Opção inválida! Tente novamente.\n");
        }
        
    } while (opcao != 0);
    
    return 0;
}
