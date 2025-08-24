#include <stdio.h>

int main () {

    int x = 10;
    int *xPtr = &x;

    printf("Pointer address: %p\n", xPtr);
    printf("Value pointed to: %d\n", *xPtr);
}
