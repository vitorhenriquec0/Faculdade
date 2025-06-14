#include <stdio.h>

int main () {
    
    float sal_atual, sal_reaj, total_reaj=0;
    char continuar;
    
    do {
    printf("Digite o salario atual:\n");
    scanf("%f", &sal_atual);
    
    if (sal_atual < 500) {
        sal_reaj = sal_atual * 1.15;
    }
    else if (sal_atual >= 500 && sal_atual <= 1000) {
        sal_reaj = sal_atual * 1.1;
    }
    else {
        sal_reaj = sal_atual * 1.05;
    }
    
    total_reaj+=sal_reaj-sal_atual;
    
    printf("O salario reajustado é: R$%.2f\n", sal_reaj);
    
    printf("Deseja calcular outro salário? (S/N)\n");
    scanf(" %c", &continuar);
        
    } while (continuar == 's' || continuar == 'S');
    
    printf("A totalização de reajustes é de: R$%.2f\n", total_reaj);
    
    return 0;
}