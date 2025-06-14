/* Escreva um programa em C para gerir o inventário de 5 produtos eletrónicos. O programa deve:
- Permitir ao utilizador introduzir dados para 5 produtos (ID, nome, categoria, preço unitário, quantidade em stock, data da última reposição).
- Calcular e exibir o valor total do stock para cada produto (preço * quantidade).
- Identificar e imprimir o produto com a maior quantidade em stock.
- Permitir ao utilizador pesquisar um produto por ID e exibir os seus detalhes.
- Imprimir um relatório de todos os produtos, incluindo o valor total do seu stock.
*/ 

#include <stdio.h>
#include <stdlib.h>

#define n 2

typedef struct {
    int ID;
    char nome[40];
    char categoria[15];
    float preco;
    float estoque;
    int dia;
    int mes;
    int ano;
} registroProduto;

int main () {
    
    registroProduto produtos[n];
    
    int maior = 0;
    int pesquisaID;
    char pesquisar;
    
    for (int i = 0; i < n; i++) {
        printf("--- PRODUTO %d ---\n\n", i + 1);
        printf("Digite o ID do produto:");
        scanf("%d", &produtos[i].ID);
        printf("Digite o nome produto:");
        scanf(" %[^\n]", produtos[i].nome);
        printf("Digite a categoria do produto:");
        scanf(" %[^\n]", produtos[i].categoria);
        printf("Digite o preço do produto: ");
        scanf("%f", &produtos[i].preco);
        printf("Digite a quantidade desse produto em estoque: ");
        scanf("%f", &produtos[i].estoque);
        printf("Digite a data da ultima reposição desse produto: (00 00 0000)");
        scanf("%d%d%d", &produtos[i].dia, &produtos[i].mes, &produtos[i].ano);
    }
    
    printf("\nValor total para cada produto (produto x estoque):");
    for (int i = 0; i < n; i++) {
        printf("\n%s = %.2f", produtos[i].nome, produtos[i].estoque * produtos[i].preco);
    }

    for (int i = 0; i < n; i++) {
        if (maior < produtos[i].estoque) {
            maior = i;
        }
    }
    printf("\n\nProduto com o maior estoque: %s - %.f", produtos[maior].nome, produtos[maior].estoque);
    
    printf("\n\nDeseja pesquisar algum produto por ID?");
    scanf(" %c", &pesquisar);
    if (pesquisar == 's' || pesquisar == 'S') {
        printf("\nDigite o ID:");
        scanf("%d", &pesquisaID);
        for (int i = 0; i < n; i++) {
            if (produtos[i].ID == pesquisaID) {
                printf("\nPRODUTO ID [%d]\n", produtos[i].ID);
                printf("\nNome: %s", produtos[i].nome);
                printf("\nCategoria: %s", produtos[i].categoria);
                printf("\nPreço unitário: R$%.2f", produtos[i].preco);
                printf("\nEstoque: %.f", produtos[i].estoque);
                printf("\nData da ultima reposição: %d/%d/%d", produtos[i].dia, produtos[i].mes, produtos[i].ano);
            }
        }
    }
    
    printf("\n--- Relatório total: ---\n");
    for (int i = 0; i < n; i++) {
        printf("\nNome: %s", produtos[i].nome);
        printf("\nID: %d", produtos[i].ID);
        printf("\nCategoria: %s", produtos[i].categoria);
        printf("\nPreço unitário: R$%.2f", produtos[i].preco);
        printf("\nEstoque: %.f", produtos[i].estoque);
        printf("\nValor total do estoque = %.2f", produtos[i].estoque * produtos[i].preco);
        printf("\nData da ultima reposição: %d/%d/%d", produtos[i].dia, produtos[i].mes, produtos[i].ano);
        printf("\n");

    }
    
    return 0;
}
