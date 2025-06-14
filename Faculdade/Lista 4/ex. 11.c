#include <stdio.h>

int main() {
    
    float  diarias, valor, total_ganho=0, total_diarias=0;
    char nome[30], endereco[40], fone[15], cidade[20], estado[20];

    for (int i = 1; i <= 2; i++) {
        printf("\nCadastro do hóspede %d:\n", i);
        
        // Limpa o buffer antes de começar
        while (getchar() != '\n');

        printf("Nome completo: ");
        scanf("%29[^\n]", nome);
        while (getchar() != '\n'); // Limpa o buffer

        printf("Endereço: ");
        scanf("%39[^\n]", endereco);
        while (getchar() != '\n');

        printf("Telefone: ");
        scanf("%14[^\n]", fone);
        while (getchar() != '\n');

        printf("Cidade: ");
        scanf("%19[^\n]", cidade);
        while (getchar() != '\n');

        printf("Estado: ");
        scanf("%19[^\n]", estado);
        while (getchar() != '\n');
        
        printf("Número de diárias: ");
        scanf("%f", &diarias);
        
        // Soma o total de diarias a cada loop
        total_diarias += diarias;

        printf("\nDados do hóspede %d:\n", i);
        printf("Nome: %s\n", nome);
        printf("Endereço: %s\n", endereco);
        printf("Telefone: %s\n", fone);
        printf("Cidade: %s\n", cidade);
        printf("Estado: %s\n", estado);
        printf("Diárias: %.0f\n", diarias);
        
        if (diarias < 15) {
            valor = (diarias * 300) + 20;
        }
        else if (diarias == 15) {
            valor = (diarias * 300) + 14;
        }
        else if (diarias > 15) {
            valor = (diarias * 300) + 12;
        }
        else {
            printf("Inválido");
        }
        
        // Soma cada valor pago pelo cliente a cada loop
        total_ganho += valor;
        
        printf("\nValor a ser pago: R$%.2f\n", valor);
    }
    
    printf("\nO total ganho pelo hotel é: R$%.2f", total_ganho);
    printf("\nO total de diarias foi de: %.0f", total_diarias);

    return 0;
}