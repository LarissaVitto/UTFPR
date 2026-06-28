#include <stdio.h>
#include <stdlib.h>

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
        printf("%d\n ", raiz->valor);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

void imprimir2(No* raiz){ //Em ordem
    if(raiz != NULL){
        imprimir2(raiz->esquerda);
        printf("%d\n ", raiz->valor);
        imprimir2(raiz->direita);
    }    
}
void imprimir3(No* raiz){ //Pós-ordem (contrário)
    if(raiz != NULL){
        imprimir3(raiz->esquerda);
        imprimir3(raiz->direita);
        printf("%d\n ", raiz->valor);
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
    imprimir2(raiz);
    imprimir3(raiz);
    return 0;
}