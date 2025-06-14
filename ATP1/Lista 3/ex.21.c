#include <stdio.h>
#include <math.h>


int main () {
    
    double a, b, c;
    double delta, x1, x2;
    
    printf("Digite os valores de a, b e c:\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    
    if (a == 0) {
        printf("Não é uma equação do 2o grau!");
        return 0;
    }
    
    delta = b * b - 4 * a * c;
    
    if (delta < 0) {
        printf("A euação não admite raízes reais.");
    }
    else if (delta == 0) {
        x1 = -b / 2 * a;
        printf("Raíz única: %.2lf\n", x1);
    }
    else {
        x1 = (-b + sqrt(delta)) / 2 * a;
        x2 = (-b - sqrt(delta)) / 2 * a;
        printf("As raízes são: x1 = %.2lf, x2 = %.2lf\n", x1, x2);
    }
    return 0;
}
