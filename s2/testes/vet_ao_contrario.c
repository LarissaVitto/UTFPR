#include <stdio.h>
int main(){
    int tam, a = 0;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tam);
    int vet[tam];
    for(int i = 0; i < tam; i++){
        printf("\nDigite o valor para a posicao %d: ", i);
        scanf("%d", &vet[i]);
        //eusoloco
        a = tam - 1;
        vet[a] = vet[i];
    }// eu fiz o vetor a virar o vetor i, a posiçao do vetor a é o vetor i - 1 dai ele inverte euacho sla 
    for(int i = 0; i < tam; i++){
        printf("\n%d", vet[a]);
        a--;
    }
    //eusoloco 
    //teruo
    for(int i = 0; i < tam / 2; i++){
        int aux = vet[tam - 1 - i];
        vet[tam - 1 - i] = vet[i];
        vet[i] = aux;
    }
    for(int i = 0; i < tam; i++){
        printf("\n vet[%d] = %d", i, vet[i]);
    }
    return 0;
}

//n - 1 - i é o uiltimo vetor