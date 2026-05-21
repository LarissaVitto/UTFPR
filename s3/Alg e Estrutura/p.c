#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no* prox;
} no;

typedef struct Pilha {
    no* topo;
} Pilha;

void iniciaPilha(Pilha *p) {
    p->topo = NULL;
}

void push(Pilha* p, int valor) { // empilhar
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->valor = valor;
    novoNo->prox = p->topo; 
    p->topo = novoNo;       
}

void pop(Pilha* p) { // desempilhar
    if (p->topo != NULL) {
        no* aux = p->topo;
        p->topo = p->topo->prox; 
        free(aux);               
    } else {
        printf("Pilha vazia\n");
    }
}

void printar(Pilha *p) {
    if (p->topo != NULL) {
        no* aux = p->topo;
        while (aux != NULL) {
            printf("[%d]\n", aux->valor);
            aux = aux->prox;
        }
    } else {
        printf("Pilha vazia.\n");
    }
}

void verificarDiferenca(Pilha* p1, Pilha* p2) {
    no* aux1 = p1->topo;
    no* aux2 = p2->topo;
    printf(" P1  ||  P2\n");
    while (aux1 != NULL && aux2 != NULL) {
        if (aux1->valor != aux2->valor) {
            printf("[%d] != [%d]\n", aux1->valor, aux2->valor);
        }else{
            printf("[%d]  = [%d]\n", aux1->valor, aux2->valor);
        }
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    if (aux1 != NULL || aux2 != NULL) {
        printf("As pilhas tem tamanhos diferentes, finalizando.\n");
    }
}

int main() {
    Pilha p1; 
    Pilha p2; 
    iniciaPilha(&p1); 
    iniciaPilha(&p2);
    push(&p1, 10);
    push(&p1, 20);
    push(&p1, 30);
    printf("----------- PILHA 1 -----------\n");
    printf("Eh pra dar 30, 20, 10\n");
    printar(&p1);
    push(&p2, 10);
    push(&p2, 25);
    push(&p2, 30);
    printf("----------- PILHA 2 -----------\n");
    printf("Eh pra dar 30, 25, 10\n");
    printar(&p2);
    printf("---------- COMPARACAO ---------\n");
    verificarDiferenca(&p1, &p2);
    printf("----------- PILHA 1 -----------\n");
    pop(&p1); 
    pop(&p1); 
    printf("Eh pra dar 10\n");
    printar(&p1);
    pop(&p1); 
    pop(&p1); //verificar se ta certo
    printar(&p1);
    return 0;
}