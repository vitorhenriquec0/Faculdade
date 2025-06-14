#include <stdio.h>
#include <stdlib.h>

#define n 50

typedef struct {
    long long int timestamp;
    float temperatura, umidade;
} MedicaoSensor;

int main () {
    
    MedicaoSensor dados[n];
    
    float somaTemp = 0;
    
    float MaiorUmidade;
    
    float menorTemp;
    int indiceMenorTemp;
    
    for (int i = 0; i < n; i++) {
        printf("Digite o %do timestamp: ", i + 1);
        scanf("%lld", &dados[i].timestamp);
        printf("Digite a temperatura: ");
        scanf("%f", &dados[i].temperatura);
        printf("Digite a umidade: ");
        scanf("%f", &dados[i].umidade);
    }
    
    for (int i = 0; i < n; i++) {
        somaTemp += dados[i].temperatura;
    }
    
    
    MaiorUmidade = 0;
    
    menorTemp = dados[0].temperatura;
    indiceMenorTemp = 0;
    
    for (int i = 0; i < n; i++) {
        if (dados[i].umidade > MaiorUmidade) {
            MaiorUmidade = dados[i].umidade;
        }
        
        if (dados[i].temperatura < menorTemp) {
            menorTemp = dados[i].temperatura;
            indiceMenorTemp = i;
        }
    }
    
    
    printf("Temperatura média: %.2f\n", somaTemp / n);
    printf("Umidade máxima registrada: %.2f\n", MaiorUmidade);
    printf("Timestamp da menor temperatura: %lld\n", dados[indiceMenorTemp].timestamp);
    
    return 0;
}
