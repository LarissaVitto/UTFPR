#include <stdio.h>

int main() {
    int i = 1, N;
    do {
        scanf("%d", &N);
        if (N <= 5 || N >= 200) {
            printf("Valor invalido! Tente novamente!\n");
        }
    } while (N <= 5 || N >= 200);
    while (i <= N) {
        if (i % 2 == 0) {
            int quadrado = i * i;
            printf("%d^2 = %d\n", i, quadrado);
        }
        i++;
    }
    return 0;
}
