#include <stdio.h>
int main()
{
    FILE *f = fopen("numeros.txt", "w");
    int i;
    for (i = 1; i <= 10; i++)
        fprintf(f, "%d\n", i);
    fclose(f);
}