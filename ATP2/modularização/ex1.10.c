#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fatorial(int n);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <numero>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]);
    if (n < 0) {
        printf("Erro: o numero deve ser nao negativo.\n");
        return 1;
    }

    char *res = fatorial(n);
    printf("%d! = %s\n", n, res);

    free(res);

    return 0;
}

char* fatorial(int n) {
    static int resultado[5000];
    int tamanho = 1;
    resultado[0] = 1;

    for (int x = 2; x <= n; x++) {
        int carry = 0;
        for (int i = 0; i < tamanho; i++) {
            int valor = resultado[i] * x + carry;
            resultado[i] = valor % 10;
            carry = valor / 10;
        }
        while (carry) {
            resultado[tamanho] = carry % 10;
            carry /= 10;
            tamanho++;
        }
    }

    char *saida = malloc(tamanho + 1);
    for (int i = 0; i < tamanho; i++) {
        saida[i] = resultado[tamanho - 1 - i] + '0';
    }
    saida[tamanho] = '\0';

    return saida;
}