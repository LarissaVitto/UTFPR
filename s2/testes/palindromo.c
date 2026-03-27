#include <stdio.h>
int main(){
    int tam, i, dif = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    int vet[tam];
    for(int i = 0; i < tam; i++){
        printf("\nDigite o valor para a posicao %d: ", i);
        scanf("%d", &vet[i]);
    }
    for(int i = 0; i < tam / 2; i++){
        if(vet[i] == vet[tam - 1 - i]){
            continue;
        }else{
            dif = 1;
            break;
        }
    }
    if(dif > 0){
        printf("\n Nao e palindromo");
    }else{
        printf("Palindromo");
    }
    for(int i = 0; i < tam; i++){
        printf("\n vet[%d] = %d", i, vet[i]);
    }
    return 0;
}