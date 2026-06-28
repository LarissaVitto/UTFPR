#include <stdio.h>
#include <stdlib.h>

int qtd = 0;

typedef struct no{
    int valor;
    struct no *esquerda;
    struct no *direita;
}No;

No* criaNoArvore(int valor){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserirNo(No* raiz, int valor){
    if(raiz == NULL){
        return criaNoArvore(valor);
    }else if(valor < raiz->valor){
        raiz->esquerda = inserirNo(raiz->esquerda, valor); 
    }else{
        raiz->direita = inserirNo(raiz->direita, valor);
    }
    return raiz;
}

void imprimir(No* raiz){ //Pré-ordem
    if(raiz != NULL){
        printf("%d\n", raiz->valor);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

void contaNo(No *raiz){
    if(raiz != NULL){ // já havia feito esse exercício aula passada mas não usei recursividade
        contaNo(raiz->esquerda);
        contaNo(raiz->direita);
        qtd++;
    }
}
int main(){
    No* raiz = NULL;
    raiz = inserirNo(raiz, 5);
    inserirNo(raiz, 2);
    inserirNo(raiz, 10);
    inserirNo(raiz, 1);
    inserirNo(raiz, 8);
    inserirNo(raiz, 20);
    inserirNo(raiz, 7);
    imprimir(raiz);
    contaNo(raiz);
    printf("Quantidade de nos: %d\n", qtd);
    return 0;
}