/* Gerir as pontuações de 8 jogadores num torneio.
- Ler o nome, equipa e as pontuações das 3 rondas para cada um dos 8 jogadores.
- Calcular a pontuação total e a média de pontuação para cada jogador. Armazenar estes valores na struct.
- Exibir os detalhes de todos os jogadores, incluindo as suas pontuações totais e médias.
- Identificar e imprimir o nome e a pontuação total do jogador com a maior pontuação total.
- Calcular e imprimir a média da pontuação total de todos os jogadores. */


#include <stdio.h>
#include <stdlib.h>

#define n 8

typedef struct {
    char nome[40];
    char equipe[15];
    int pontuacoes[3];
    int pontuacaoTotal;
    float pontuacaoMedia;
} registroJogador;

int main () {
    
    registroJogador jogadores[n];
    
    int indiceMaiorPontuacaoTotal = 0;
    float totalPontuacao = 0;
    float mediaTotalPontuacao;
    
    for (int i = 0; i < n; i++) {
        
        jogadores[i].pontuacaoTotal = 0;
        
        printf("\n--- JOGADOR %d ---\n\n", i + 1);
        printf("Digite o nome:");
        scanf(" %[^\n]", jogadores[i].nome);
        printf("Digite a equipe:");
        scanf(" %[^\n]", jogadores[i].equipe);
        for (int j = 0; j < 3; j++) {
            printf("Digite a %da pontuacao do jogador: ", j + 1);
            scanf("%d", &jogadores[i].pontuacoes[j]);
            jogadores[i].pontuacaoTotal += jogadores[i].pontuacoes[j];
            totalPontuacao += jogadores[i].pontuacoes[j];
        }
        
        jogadores[i].pontuacaoMedia = jogadores[i].pontuacaoTotal / 3;
        
        if (jogadores[i].pontuacaoTotal > jogadores[indiceMaiorPontuacaoTotal].pontuacaoTotal) {
            indiceMaiorPontuacaoTotal = i;
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("\n\n___ JOGADOR %d ___\n", i + 1);
        printf("\nNome: %s", jogadores[i].nome);
        printf("\nEquipe: %s", jogadores[i].equipe);
        for (int j = 0; j < 3; j++) {
            printf("\nPontuação %d: %d pontos", j + 1, jogadores[i].pontuacoes[j]);
        }
        printf("\nPontuação total: %d", jogadores[i].pontuacaoTotal);
        printf("\nPontuação média: %.2f", jogadores[i].pontuacaoMedia);
    }
    
    mediaTotalPontuacao = totalPontuacao / (n * 3.0);
    
    printf("\n\n INFORMAÇÕES ADICIONAIS: \n");
    printf("\nJogador com a maior pontuação total: %s (%d pontos)", jogadores[indiceMaiorPontuacaoTotal].nome, jogadores[indiceMaiorPontuacaoTotal].pontuacaoTotal);
    printf("\nMédia da pontuação total dos jogadores: %.2f", mediaTotalPontuacao);
    
    return 0;
}
