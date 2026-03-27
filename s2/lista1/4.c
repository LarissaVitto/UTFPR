#include <stdio.h>
int main(){
    int N;
    scanf("%d", &N);
    float vet[N], X;
    for(int i = 0; i < N; i++){
        scanf("%f", &vet[i]);
    }
    scanf("%f", &X);
    for(int i = 0; i < N; i++){
        if(vet[i] < X){
            printf("V[%d] = %.2f\n", i, vet[i]);
        }
    }
    return 0;
}