#include <stdio.h>
int main(void) {
int a = 1200;
int b = 500;
int x = 0;
int *d = &x;
*d = a + b;
printf("Valor de x: %d.\n", x);
return 0;
}