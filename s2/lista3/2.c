#include <stdio.h>
int inverter(int n, int vet[]);
int main(){
    int n;
    scanf("%d", &n);
    int vetor[n];
        
    for (int i=0; i<n; i++){
        scanf("%d", &vetor[i]);
    }
    inverter(n, vetor);
    //printVetor(n, vetor);
}
int inverter(int n, int vet[]){
    for(int i = n - 1; i >= 0; i--){
        scanf("%d", &vet[i]);
    }
    return n, vet;
}