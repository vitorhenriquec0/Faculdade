#include <stdio.h>

int main () {
    
    int dia, mes, ano;
    char *nomes_meses[] = { "", "Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro" };
    
    printf("Digite a data (DD/MM/AAAA): ");
    scanf("%d %d %d", &dia, &mes, &ano);
    
    printf("%d de %s de %d", dia, nomes_meses[mes], ano);
    
    return 0;
}
