#include <stdio.h>
int main(){
    int tam;
    double media = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    double vet[tam];
    for(int i = 0; i < tam; i++){
        printf("\nDigite o valor para a posicao %d: ", i);
        scanf("%lf", &vet[i]);
        media = media + vet[i];
    }
    media = media / tam;
    printf("\n%.2lf", media);

    return 0;
}

