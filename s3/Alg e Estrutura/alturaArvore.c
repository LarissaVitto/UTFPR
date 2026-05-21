/*Questão 3. Implemente a função int alturaArvore (PtrNoArvore *no) que retorna a altura da
árvore. Considere que:
● Uma árvore vazia tem altura -1
● Uma árvore com apenas um nó tem altura 0
● A altura é o número de arestas no caminho mais longo da raiz até uma folha*/

#include <stdio.h>
#include <stdlib.h>

int altura = -1;


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

int alturaArvore(No* raiz){
    if(raiz == NULL){
        return -1;
    }else{
        int alturaEsquerda = alturaArvore(raiz->esquerda);
        int alturaDireita = alturaArvore(raiz->direita);
        if(alturaEsquerda > alturaDireita){
            return alturaEsquerda + 1;
        }else{
            return alturaDireita + 1;
        }
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
    printf("Altura da arvore: %d\n", alturaArvore(raiz));
    return 0;
}