#include <stdio.h>

int main () {
    
    int soma_a=0, soma_b=0, soma_c=0, soma_d=0, soma_branco=0, soma_nulo=0, total_votos=0;
    int votos;
    char continuar;
    
    do {
    printf("Digite o voto para o candidato:\n");
    scanf("%d", &votos);
    
    switch (votos) {
        case 1: soma_a += 1; break;
        case 2: soma_b += 1; break;
        case 3: soma_c += 1; break;
        case 4: soma_d += 1; break;
        case 5: soma_nulo += 1; break;
        case 6: soma_branco += 1; break;
        default: printf("Voto inválido!\n");
    }
    
    total_votos += 1;
    
    printf("Prosseguir para outro voto? (S/N):\n");
    scanf(" %c", &continuar);
    } while (continuar == 's' || continuar == 'S');
    
    printf("\nTOTAL DE VOTOS: %d\n", total_votos);
    printf("\nO candidato 1 recebeu %d voto(s)", soma_a);
    printf("\nO candidato 2 recebeu %d voto(s)", soma_b);
    printf("\nO candidato 3 recebeu %d voto(s)", soma_c);
    printf("\nO candidato 4 recebeu %d voto(s)", soma_d);
    printf("\nVotos em branco: %d", soma_branco);
    printf("\nVotos nulos: %d", soma_nulo);
    
    printf("\nPercentual dos votos nulos e em branco: %.2f%%\n", ((float)(soma_nulo + soma_branco) / total_votos) * 100);

    
}
