#include <stdio.h>

int main()
{
    FILE *fp;
    int num;

    fp = fopen("numeros.txt", "r");

    if (fp != NULL) {
        while (!feof(fp)) {
            fscanf(fp, "%d", &num);
            printf("Numero lido: %d\n", num);
        }
        fclose(fp);
    }
    return 0;
}