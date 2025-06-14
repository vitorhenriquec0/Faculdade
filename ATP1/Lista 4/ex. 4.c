#include <stdio.h>

int main () {
    
    int kwh;
    float valor;
    char continuar;
    
    do {
        printf("\nDigite a quantidade de kwh: \n");
        scanf("%d", &kwh);
        
        if (kwh > 150) {
            valor = 195 + (kwh - 150)*2;
        }
        else if (kwh >= 101 && kwh <= 150) {
            valor = 115 + (kwh - 100)*1.6;
        }
        else if (kwh >=51 && kwh <= 100) {
            valor = 50 + (kwh - 50)*1.3;
        }
        else {
            valor = kwh;
        }
        printf("O valor da conta de energia é: R$%.2f\n", valor);
        
        printf("Digite <s> se deseja recalcular:\n");
        scanf(" %c", &continuar);
    } while (continuar == 's');
    return 0;
}