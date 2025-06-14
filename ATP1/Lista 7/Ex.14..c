#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int hora;
    int minuto;
} Time;

int main() {
    
    Time startTime, endTime;
    
    int totalMinutesStart, totalMinutesEnd;
    int totalMinutes;
    
    printf("\nDigite a hora e o minuto de início do jogo: ");
    scanf("%d%d", &startTime.hora, &startTime.minuto);
    
    printf("\nDigite a hora e o minuto de término do jogo:");
    scanf("%d%d", &endTime.hora, &endTime.minuto);
    
    totalMinutesStart = startTime.hora * 60 + startTime.minuto;
    totalMinutesEnd = endTime.hora * 60 + endTime.minuto;
    
    if (totalMinutesEnd >= totalMinutesStart) {
        totalMinutes = totalMinutesEnd - totalMinutesStart;
    } else {
        totalMinutes = (24 * 60 - totalMinutesStart) + totalMinutesEnd;
    }
    
    printf("\nO jogo durou %d horas e %d minutos", totalMinutes / 60, totalMinutes % 60);
    
    printf("\n\nO jogo durou %d minutos", totalMinutes);
    
    printf("\n\nApenas segundos: %d segundos", totalMinutes * 60);
    
    return 0;
}
    
    