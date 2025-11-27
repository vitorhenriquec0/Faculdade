/*
Implemente um programa que receba uma sequência A ∈ ZN com N números natu
rais, de modo que, a diferença entre quaisquer elementos consecutivos é constante, isto
 é, xi − xi−1 = c, para algum c ∈ N. Em seguida, imprima na saída padrão da aplicação o
 termo faltante nessa sequência.
*/

#include <stdio.h>

int Faltante(int v[], int n);

int main() {
    int v[] = {2, 4, 6, 10, 12}; 
    int n = 5;

    int faltante = Faltante(v, n);
    
    printf("O termo faltante eh: %d\n", faltante);

    return 0;
}

int Faltante(int v[], int n) {
    // Qual o tamanho da razão?
    // Se não faltasse nada, seria (v[n-1] - v[0]) / (n-1).
    // Como falta um, dividimos por 'n'.
    int c = (v[n-1] - v[0]) / n;

    // Se a razão é 0 (ex: 5, 5, 5), falta um 5.
    if (c == 0) return v[0];

    int e = 0;
    int d = n - 1;

    while (e < d) {
        int m = (e + d) / 2;

        // valor = primeiro valor + (Passos * Tamanho)
        int valorEsperado = v[0] + (c * m);

        if (v[m] == valorEsperado) {
            // O problema está mais pra frente.
            e = m + 1;
        } else {
            // v[m] > esperado. O valor está errado (alto demais).
            // O degrau foi arrancado ANTES daqui. Vamos olhar pra trás.
            d = m;
        }
    }

    // v[m] > esperado. A altura está errada (alta demais).
    // O degrau foi arrancado ANTES daqui. Vamos olhar pra trás.
    return v[0] + (e * c);
}