// Implemente uma função recursiva que, dado um numero x e n, faça x elevado a n

int potencia(int x, int n);

int main() {
    int x, n;
    scanf("%d%d", &x, &n);

    printf("%d elevado a %d eh igual a: %d", x, n, potencia(x, n));

    return 0;
}

int potencia(int x, int n) {
    if (n == 0) return 1;
    return x * potencia(x, n - 1);
}