#include <stdio.h>
#include <stdlib.h>

typedef struct No{ // elemento da pilha
    char valor; //pode ser qlq coisa

    struct No *prox;
}No;
typedef struct{
    No *topo; //ref p topo da lista
}Pilha;

pilha *criar_pilha(){
    pilha *p = (pilha*)
        malloc(sizeof(pilha)); //alocada memoria pra pilha
    p->topo = NULL; //inicializa topo como nulo
    return p;
}

No* criar_no(char valor){
    No *n = (No*) malloc(sizeof(No)); //alocada memoria pro no
    n->valor = valor; //passa valor pro no
    n->prox = NULL; //inicializa proximo valor do no como nulo
    return n;
}
    
int eh_vazia(Pilha *p){
    return p->topo == NULL; //1 se a pilha estiver vazia se nao 0, se o topo for nulo a pilha eh vazia
}

void empilhar(Pilha *p, char valor){
    No *no = criar_no(valor); //cria um novo no com o valor a ser empilhado
    no->prox = p->topo; //faz o novo no apontar para o topo atual da pilha encadeando
    p->topo = no; //faz o topo da pilha ser o novo no    
}

char desempilhar(Pilha *p){
    if(eh_vazia(p)){
        printf("Pilha vazia\n");
        return "\0";
    }
    No* aux = p->topo; //no auxiliar q recebe o topo
    p->topo = aux->prox; //ta pegando o proximo do auxiliar q é o anterior q no caso vira o segundo da pilha
    char valor = aux->valor; //pega o valor do no auxiliar
    free(aux);
    return valor;
}

void imprimir_pilha(Pilha *p){
    No *aux = p->topo; //no auxiliar q recebe o topo
    while(aux != NULL){ //enquanto o no auxiliar nao for nulo
        printf("%c ", aux->valor); //imprime o valor do no auxiliar
        aux = aux->prox; //faz o no auxiliar receber o proximo no da pilha
    }
    printf("\n");
}

int main(){
    Pilha *p = criar_pilha(); 
    empilhar(p, 'A');
    empilhar(p, 'B');
    empilhar(p, 'C');
    imprimir_pilha(p);
    printf("%c\n", desempilhar(p)); 
    return 0;
}