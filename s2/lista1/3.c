#include <stdio.h>
int main(){
    int tamanho;
    scanf("%d", &tamanho);
    double matriz[tamanho][tamanho];
    double resposta[tamanho][tamanho];
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            scanf("%lf", &matriz[i][j]);
            resposta[i][j] = 0.0;
        }
    }
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
           for (int k = 0; k < tamanho; k++) {
                resposta[i][j] += matriz[i][k] * matriz[k][j];
            }
        }
    }
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            printf ("%.1lf ",  resposta[i][j]);
        }
        printf("\n");
    }
    return 0;
}
