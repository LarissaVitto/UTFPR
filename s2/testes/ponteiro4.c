#include <stdio.h>
void calcStats(int n, double v[n], double *min, double *max, double *freq, double *avg);
int main() {
    double menor, maior, moda, media;
    int N;

    printf("Digite o tamanho do vetor:\n");
    scanf("%d", &N);
    double vet[N];

    for (int i = 0; i < N; i++) {
        printf("\nDigite o valor [%d]:\n", i);
        scanf("%lf", &vet[i]);
    }
    calcStats(N, vet, &menor, &maior, &moda, &media);
    printf("Menor Valor: %.2lf\n", menor);
    printf("Maior Valor: %.2lf\n", maior);
    printf("Moda Valor: %.2lf\n", moda);
    printf("Media Valor: %.2lf\n", media);
    return 0;
}

void calcStats(int n, double v[n], double *min, double *max, double *freq, double *avg) {
    double somando = 0;
    int moda = 0; 
    *min = v[0];
    *max = v[0];

    for (int i = 0; i < n; i++) {
        if (v[i] < *min) *min = v[i];
        if (v[i] > *max) *max = v[i];

        int contador = 0;

        for (int j = 0; j < n; j++) {
            if (v[j] == v[i]) {
                contador++;
            }
        }
        if (contador > moda) {
            moda = contador;
            *freq = v[i];
        }
        somando += v[i];
    }
    *avg = somando / n;
}
