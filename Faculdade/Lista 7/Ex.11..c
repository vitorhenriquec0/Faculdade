/* 11. Faça um programa capaz de ler as coordenadas (x e y) que definem cinco pontos em um plano cartesiano.
Considere o primeiro ponto como referência e, em seguida, o programa deve imprimir o ponto lido que
tem a menor distância em relação ao ponto de referência. Apresente também a distância entre os dois
pontos. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define n 5

typedef struct {
    int x[n];
    int y[n];
} coordenadas;

int main() {
    
    int aux = 0;
    int maisProximo = 1;
    double menorDistancia, distancia;
    
    coordenadas valores;
    
    printf("Digite a origem X e Y:");
    scanf("%d%d", &valores.x[0], &valores.y[0]);
    
    for (int i = 1; i < n - 1; i++) {
        printf("\nDigite o %do valor de X e Y:\n", i);
        scanf("%d%d", &valores.x[i], &valores.y[i]);
    }
    
    menorDistancia = sqrt(
        (valores.x[1] - valores.x[0]) * (valores.x[1] - valores.x[0]) +
        (valores.y[1] - valores.y[0]) * (valores.y[1] - valores.y[0])
    );
    
    for (int i = 2; i < n; i++) {
        distancia = sqrt(
            (valores.x[i] - valores.x[0]) * (valores.x[i] - valores.x[0]) +
            (valores.y[i] - valores.y[0]) * (valores.y[i] - valores.y[0]));
            
        if (distancia < menorDistancia) {
            menorDistancia = distancia;
            maisProximo = i;
        }
    }
    
    printf("\nPonto mais próximo: (%d, %d)\n", valores.x[maisProximo], valores.y[maisProximo]);
    printf("Distância: %.2lf\n", menorDistancia);
    
    return 0;
}