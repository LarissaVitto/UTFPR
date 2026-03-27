#include <stdio.h>

int main() {
    int N, M, uau = 0, menor, minmax;
    scanf("%d %d", &N, &M);
    int mat[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
    menor = mat[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (mat[i][j] < menor) {
                menor = mat[i][j];
                uau = i;
            }
        }
    }
    minmax = mat[uau][0];
    for (int j = 0; j < M; j++) {
        if (mat[uau][j] > minmax) {
            minmax = mat[uau][j];
        }
    }
    printf("MinMax = %d\n", minmax);
    return 0;
}