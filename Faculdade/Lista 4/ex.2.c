#include <stdio.h>

int main () {
    
    float kwh, valor;
    char aposentado, continuar;
    
    do {
        printf("Digite a quantidade de KwH consumidas:\n");
        scanf("%f", &kwh);
        
        printf("Digite <s> se você é aposentado:\n");
        scanf(" %c", &aposentado);
        
        if (aposentado == 's') {
            printf("O valor a pagar é: R$%.2f\n", (kwh*0.1)*0.85);
        }
        else {
            printf("O valor a pagar é: R$%.2f\n", kwh*0.1);
        }
        
        printf("Digite <s> se deseja recalcular:\n");
        scanf(" %c", &continuar);
    } while (continuar == 's');
    
    return 0;
}