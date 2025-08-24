/*
Crie um programa que leia a partir de um arquivo um número real x, e escreva no
mesmo arquivo a saída da função f(x) = √1 + x2.
*/

#include <stdio.h>
#include <math.h>

float calculo(int num);

int main() {

    FILE *fp = fopen("exercicio1.txt", "r+");

    int num;

    if (fp != NULL) {
        fscanf(fp, "%d", &num);
        printf("%.2f", calculo(num));
        fseek(fp, 0, SEEK_END);
        fprintf(fp, "\n%.2f\n", calculo(num));
        fclose(fp);
    }
    
    
    return 0;
}

float calculo(int num) {
    return sqrt(1 + pow(num, 2));
}