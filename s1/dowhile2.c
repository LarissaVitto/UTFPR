#include <stdio.h>

int main() {
    int i = 1, N;
    do {
        scanf("%d", &N);
        if (N <= 2 || N >= 1000) {
            printf("Valor invalido! Tente novamente!\n");
        }
    } while (N <= 2 || N >= 1000);
    while (i <= 10) {
        int result = i * N;
        printf("%d X %d = %d\n", i, N, result);
        i++;
    }
    return 0;
}
