/*
Crie uma função que recebe uma cadeia de caracteres S e um caractere c e retorne a
primeira e a última ocorrência de c na cadeia S. Caso não houver nenhuma ocorrência de
c em S, retorne −1 para ambas ocorrências.
*/

#include <stdio.h>

void findC(const char *S, char C, int *first, int *last);

int main() {
    char string[100];
    char character;
    int first, last;

    printf("Enter the text: ");
    scanf(" %[^\n]", string);

    printf("Enter the character to find: ");
    scanf(" %c", &character);

    findC(string, character, &first, &last);

    printf("First occurrence: %d\n", first);
    printf("Last occurrence: %d\n", last);

    return 0;
}

void findC(const char *S, char C, int *first, int *last) {
    *first = -1;
    *last = -1;

    int i = 0;
    while (S[i] != '\0') {
        if (S[i] == C) {
            if (*first == -1) {
                *first = i;
            }
            *last = i;
        }
        i++;
    }
}
