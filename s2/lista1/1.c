#include <stdio.h>
int main(){
    int N, tam, j;
    scanf("%d", &N);
    if(N % 2 == 0 || N == 0){
        tam = N / 2;
    }else{
        tam = (N / 2) + 1;
    }
    int vet[N];
    int vet2[tam];
    for(int i = 0; i < N; i++){
        scanf("%d", &vet[i]);
    }
    for(int k = 0; k < N; k++){
        if(k % 2 == 0){
            vet2[j] = vet[k];
            j++;
        }
    }
    for(int i = 0; i < tam; i++){
        printf("Y[%d] = %d\n", i, vet2[i]);
    }
    return 0;
}
