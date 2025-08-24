/*
Crie uma função que receba quatro número reais x1, y1, x2, y2 e que retorne a distância
euclidiana entre os pontos P1 = (x1, y1) e P2 = (x2, y2).
*/

#include <stdio.h>
#include <math.h>

double distancia(double x1, double y1, double x2, double y2);

int main () {
    double x1, x2;
    double y1, y2;

    printf("Digite os valores de x1 e y1\n");
    scanf("%lf%lf", &x1, &y1);
    printf("Digite os valores de x2 e y2\n");
    scanf("%lf%lf", &x2, &y2);

    printf("%.2lf", distancia(x1, y1, x2, y2));

    return 0;
}

double distancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));
}