#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int vet[1000];
    int soma_vet = 0, soma_par = 0, soma_impar = 0;
    int par = 0, impar = 0;
    
    srand(time(NULL));
    
    for (int i = 0; i < 1000; i++){
        vet[i] = rand() % 100;
    }
    
    for (int i = 0; i < 1000; i++){
        soma_vet += vet[i];
    }
    
    printf("A media dos 1000 números é: %d\n", soma_vet / 1000);
    
    for (int i = 0; i < 1000; i++){
        if (vet[i] % 2 == 0) {
            soma_par += vet[i];
            par++;
        }
        else {
            soma_impar += vet[i];
            impar++;
        }
    }
    
    printf("A media dos numeros pares é: %d\n", soma_par / par);
    printf("A media dos numeros impares é: %d\n", soma_impar / impar);
    printf("O total de numeros pares é: %d\n", par);
    printf("O total de numeros impares é: %d\n", impar);
    
    return 0;
}
