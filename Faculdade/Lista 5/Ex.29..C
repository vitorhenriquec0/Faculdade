/* 29. Escreva um programa para ler 10 nomes. Os nomes devem ser armazenados em dois vetores
de strings (str1 e str2), cinco nomes em cada vetor. O tamanho máximo de cada string deve
ser 60 caracteres. O programa deve mostrar str1 e str2. Em seguida, a string str3 deve
armazenar os nomes contidos em str1 e str2. Apresentar a string str3. */

#include <stdio.h>

#define n 5

int main() {
    
    char str1[n][61], str2[n][61], str3[n * 2][61];
    
    printf("Digite 10 nomes: \n");
    for (int i = 0; i < n +n; i++) {
        if (i < n) {
            scanf(" %[^\n]", str1[i]);
        }
        else {
            scanf(" %[^\n]", str2[i - 5]);
        }
    }
    
    printf("\n--- Nomes em str1 e str2 ---\n");
    for (int i = 0; i < n + n; i++) {
        if (i < n) {
            printf("Str1[%d]: %s\n", i, str1[i]);
        }
        else {
            printf("Str2[%d]: %s\n", i, str2[i - 5]);
        }
    }
    
    for (int i = 0; i < n + n; i++) {
       if (i < n) {
           int j = 0;
           while (str1[i][j] != '\0') {
               str3[i][j] = str1[i][j];
               j++;
           }
           str3[i][j] = '\0';
       } else {
           int j = 0;
           while (str2[i - 5][j] != '\0') {
               str3[i][j] = str2[i - 5][j];
               j++;
           }
           str3[i][j] = '\0';
       }
    }
    
    printf("\n--- Nomes em str3 ---\n");
    for (int i = 0; i < n * 2; i++) {
        printf("\nStr3[%d]: %s",i, str3[i]);
    }
    
    return 0;
}
