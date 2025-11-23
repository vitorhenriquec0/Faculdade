/*
Construa um programa que receba da entrada padrão da aplicação dois vetores A1, A2 ∈
RN com N números reais, e imprima na saída padrão da aplicação a mediana do vetor
resultante da combinação de A1 e A2.
*/

void concatenar(int a[], int b[], int c[], int N);
void ShellSort(int v[], int N);
float Mediana(int v[], int Ntotal);

int main() {

    int a[5] = {7, 80, 30, 43, 2};
    int b[5] = {1, 30, 21, 9, 50};

    int c[10];

    int N = 5;

    concatenar(a, b, c, N);
    ShellSort(c, N * 2);

    float resultado = Mediana(c, N * 2);

    printf("Mediana: %.2f", resultado);

    return 0;

}

void concatenar(int a[], int b[], int c[], int N) {
    for (int i = 0; i < N; i++) {
        c[i] = a[i];
    }
    for (int i = 0; i < N; i++) {
        c[N + i] = b[i];
    }
}

void ShellSort(int v[], int n) {
    int gap = 1;
    while (gap < n) gap = gap * 3 + 1;

    while (gap > 1) {
        gap /= 3;

        for (int i = gap; i < n; i++) {
            int temp = v[i];
            int j;

            for (j = i; j >= gap && v[j - gap] > temp; j -= gap) {
                v[j] = v[j - gap];
            }
            v[j] = temp;
        }
    }
}

float Mediana(int v[], int Ntotal) {

    int m1 = (Ntotal / 2) - 1;
    int m2 = Ntotal / 2;

    float mediana = (v[m1] + v[m2]) / 2.0;
    return mediana;
}