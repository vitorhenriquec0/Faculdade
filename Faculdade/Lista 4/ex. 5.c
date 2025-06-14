#include <stdio.h>

int main () {
    
    int codigo;
    char continuar;
    
    do {
        printf("\nDigite o codigo:\n");
        scanf("%d", &codigo);
        
        printf("Produto de código %d: ", codigo);
        
        switch (codigo) {
            case 1: printf("Alimento não perecível"); break;
            case 2 ... 4: printf("Alimento perecível"); break;
            case 5 ... 6: printf("Vestuário"); break;
            case 7: printf("Higiene pessoal"); break;
            case 8 ... 13: printf("Limpeza e utensílios domésticos"); break;
            default: printf("Inválido");
        }
        
        printf("\nDigite <s> se deseja continuar:");
        scanf(" %c", &continuar);
    } while (continuar == 's');
    return 0;
}