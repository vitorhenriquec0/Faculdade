#include <stdio.h>

int main () {
    
    int codigo [10];
    
    printf("Digite os 10 codigos:\n");
    
    for (int i=0; i<10; i++) {
        printf("Produto %d: ", i + 1);
        scanf("%d", &codigo[i]);
    }
    
    printf("\nProcedências:\n");
    
    for (int i=1; i<10; i++) {
        printf("Produto %d (codigo %d): ", i + 1, codigo[i]);
        
        switch (codigo[i]) {
            case 1: printf ("Sul\n"); break;
            case 2: printf ("Norte\n\n"); break;
            case 3: printf ("Leste\n"); break;
            case 4: printf ("Oeste\n"); break;
            case 5 ... 6: printf ("Nordeste\n"); break;
            case 7 ... 9: printf ("Sudeste\n"); break;
            case 10 ... 11: printf ("Centro-Oeste\n"); break;
            case 12 ... 15: printf ("Nordeste\n"); break;
            default: printf ("Importado\n");
        }
    }
    
    return 0;
}