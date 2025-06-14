/* Simular o movimento de 2 planetas num espaço 2D durante 5 passos de tempo.
- Ler o nome inicial, posição (x, y) e velocidade (vx, vy) para 2 planetas.
- Para cada passo de tempo (de 1 a 5):
  Atualizar a posição de cada planeta: nova_x=antiga_x+vx, nova_y=antiga_y+vy. 
  mprimir o número do passo de tempo e o nome e nova posição de cada planeta.
- Após 5 passos de tempo, calcular e imprimir a distância final de cada planeta à origem (0,0).

A distância d de um ponto (x,y) à origem é d=x2+y2. */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Ponto2d;

typedef struct {
    char nome[40];
    Ponto2d posicaoAtual;
    Ponto2d velocidade;
} Planeta;

float calcularDistanciaOrigem(Ponto2d ponto) {
    return sqrt(pow(ponto.x, 2) + pow(ponto.y, 2));
}

int main () {
    Planeta planetas[2];
    
    int numPassosTempos = 5;
    float distancia;
    
    for (int i = 0; i < 2; i++) {
        printf("\n --- Planeta %d ---\n\n", i + 1);
        printf("Digite o nome do planeta:");
        scanf(" %[^\n]", planetas[i].nome);
        
        printf("Digite a posicao inicial (x y): ");
        scanf("%f %f", &planetas[i].posicaoAtual.x, &planetas[i].posicaoAtual.y);

        printf("Digite a velocidade inicial (vx vy): ");
        scanf("%f %f", &planetas[i].velocidade.x, &planetas[i].velocidade.y);
        
        printf("\n");
    }
    
    printf("\n--- Simulação de Movimento ---\n\n");
    
    for (int i = 0; i < numPassosTempos; i++) {
        printf("\n--- Passo de Tempo: %d ---\n", passo + 1);
        for (int j = 0; j < 2; j++) {
            planetas[j].posicaoAtual.x += planetas[j].velocidade.x;
            planetas[j].posicaoAtual.y += planetas[j].velocidade.y;
            
            printf("Planeta %s | Nova posição: (%.f, %.f)\n",
            planetas[j].nome, planetas[j].posicaoAtual.x, planetas[j].posicaoAtual.y);
        }
    }
    
    printf("\n\nDistâncias finais a origem:\n");
    for (int i = 0; i < 2; i++) {
        distancia = calcularDistanciaOrigem(planetas[i].posicaoAtual);
        printf("Planeta: %s | Distancia a origem: %.2f unidades\n",
               planetas[i].nome, distancia);
    }
    return 0;
}
