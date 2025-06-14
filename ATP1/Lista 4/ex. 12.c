#include <stdio.h>

#define TOTAL_PESSOAS 50

int main() {
    
    int homens=0, mulheres=0;
    float altura, soma_altura_mulheres=0;
    float maior_altura_m=0, menor_altura_m=3.0;
    float maior_altura_f=0, menor_altura_f=3.0;
    float media_altura_mulheres, diferenca_percentual;
    char sexo;
    
    for (int i=1; i<=TOTAL_PESSOAS; i++) {
        
        printf("\nPessoa %d:\n", i);
        
        printf("Digite a altura (em metros):\n");
        scanf("%f", &altura);
        printf("Digite o sexo:\n");
        scanf(" %c", &sexo);
        
        if (sexo == 'M'){
            homens++;
            
            if (altura > maior_altura_m) maior_altura_m = altura;
            if (altura < menor_altura_m) menor_altura_m = altura;
        }
        else {
            mulheres++;
            soma_altura_mulheres += altura;
            
            if (altura > maior_altura_f) maior_altura_f = altura;
            if (altura < menor_altura_f) menor_altura_f = altura;
        }
    }
    
    media_altura_mulheres = soma_altura_mulheres / mulheres;
    diferenca_percentual = ((homens - mulheres) / TOTAL_PESSOAS)*100;
    
    // Resultados
    
    printf("\n\nRESULTADOS:\n");
    printf("a) Alturas extremas:\n");
    printf("Masculino: Maior = %.2fm, Menor = %.2fm\n", maior_altura_m, menor_altura_m);
    printf("Feminino: Maior = %.2fm, Menor = %.2fm\n", maior_altura_f, menor_altura_f);
    printf("b) Altura média das mulheres: %.2fm\n", media_altura_mulheres);
    printf("c) Quantidade de homens: %d\n", homens);
    printf("Diferença percentual: %.1f%%\n", diferenca_percentual);
    
    return 0;
}