#include <stdio.h>

#define n 2

int main()
{
    float matA[n][n], matB[n][n];
    float constante;
    char escolha;
    
    printf("Digite 4 valores inteiros para a 1a matriz:\n");
    for (int i =0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &matA[i][j]); // Leitura da Matriz A
        }
    }
    
    printf("Digite 4 valores inteiros para a 2a matriz:\n");
    for (int i =0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%f", &matB[i][j]); // Leitura da MAtriz B
        }
    }
    
    printf("--------- MENU ---------\n");
    printf("\na) Somar as duas matrizes\n");
    printf("b) Subtrair a primeira matriz da segunda\n");
    printf("c) Adicionar uma constante as duas matrizes\n");
    printf("d) Imprimir as matrizes\n");
    
    scanf(" %c", &escolha);
    
    if (escolha == 'a') {
        
        float matC[3][3];
        
        printf ("\nSoma das matrizes A e B:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matC[i][j] = matA[i][j] + matB[i][j]; // Somando a matriz A e B e armazenando na matriz C
                printf("%.0f ", matC[i][j]);
            }
            printf("\n");
        }
    }
    else if (escolha == 'b') {
        
        float matC[3][3];
        
        printf("\nMatriz da subtração de A em B:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matC[i][j] = matB[i][j] - matA[i][j]; // Subtraindo a matriz A na matriz B e armazenando na matriz C
                printf("%.0f ", matC[i][j]);
            }
            printf("\n");
        }
    }
    else if (escolha == 'c') {
        printf("Digite uma constante:\n");
        scanf("%f", &constante);
        
        printf("\nMatriz A com a constante:\n");
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%.0f ", matA[i][j] + constante); // Imprimindo a matriz A somada a constante
            }
            printf("\n");
        }
        
        printf("\nMatriz B com a constante:\n");
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%.0f ", matB[i][j] + constante); // Imprimindo a Matriz B somada a constante
            }
            printf("\n");
        }
    }
    else if (escolha == 'd') {
        
        printf("\nMatriz A:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%.0f ", matA[i][j]);
            }
            printf("\n");
        }
        
        printf("Matriz B:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%.0f ", matA[i][j]);
            }
            printf("\n");
        }
    }
    else {
        printf("Opção inválida!");
    }
    
    return 0;
}
