#include <stdlib.h>
#include <stdio.h>

int buscaSequencial(int *vetor, int valor){
    int i;
    for(i = 0; i < 10; i++){
        if(vetor[i] == valor){
            printf("Valor encontrado na posicao: %d\n", i);
            return i;
        }
    }
    printf("Valor nao encontrado\n");
    return -1;
}

int buscaBinaria(int *vetor, int tam, int valor){
    int inicio = 0, fim = tam - 1;
    int meio;

    while (inicio <= fim) {
        meio = (fim + inicio) / 2;

        if (vetor[meio] == valor){
            printf("Valor encontrado na posicao: %d\n", meio);
            return meio; 
        } else if(vetor[meio] < valor){ //da pra fazer assim pq é um else dai ele volta pro while e continua tentando.
            inicio = meio + 1; // Busca na metade da direita
        } else {
            fim = meio - 1; // Busca na metade da esquerda
        }
    } 
    
    // Se o laço terminar e não encontrar, exibe a mensagem
    printf("Valor nao encontrado\n");
    return -1;
}

int main(){
    int vetor[10] = {5,3,6,9,8,4,1,12,85,7};
    buscaSequencial(vetor, 9);
    buscaSequencial(vetor, 11); // não tem

// só pra separar
    
    int vetorOrdenado[10] = {1,3,4,5,6,7,8,9,12,85};
    buscaBinaria(vetorOrdenado, 10, 9);
    buscaBinaria(vetorOrdenado, 10, 11); // não tem
    
    return 0;
}