/* 16. Apresentar os resultados de uma tabuada de um número qualquer (digitado pelo usuário). A
tabuada deve ser escrita no seguinte formato: multiplicando x multiplicador = resultado. (Ex.
2 x 2 = 4). Todos os valores devem ser calculados e apresentados ao final, seguindo o formato
indicado. */

#include <stdio.h>

int main () {
    
    int multiplicando;
    
    printf("Digite um número: ");
    scanf("%d", &multiplicando);
    
    for (int i = 0; i < 11; i++) {
        printf("\n%d x %d = %d", multiplicando, i, multiplicando * i);
    }
    
    return 0;
}