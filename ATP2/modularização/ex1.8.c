/* Crie uma função que receba um número inteiro longo não negativo n e que imprima
na saída padrão da aplicação a representação binária deste número. */

#include <stdio.h>

void convertDecimalToBinary(int decimal);

int main() {

    int decimalNumber;
    
    printf("Enter the decimal number to be converted: ");
    scanf("%d", &decimalNumber);

    convertDecimalToBinary(decimalNumber);

    return 0;

}

void convertDecimalToBinary(int decimal) {

    if (decimal == 0) {
        printf("\n0\n");
        return;
    }

    int binaryNumber[32];
    int i = 0;
    
    while (decimal > 0) {
        binaryNumber[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }

    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binaryNumber[j]);
    }
}