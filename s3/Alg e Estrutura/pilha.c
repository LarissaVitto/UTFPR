#include <stdio.h>

// Correção 1: Removido o '=='
#define TAM 10 

typedef struct {
    int vetor[TAM];
    int topo;
} PilhaEstatica;

void empilhar(PilhaEstatica *p, int valor) {
    if (p->topo < TAM) {
        p->vetor[p->topo] = valor;
        p->topo++;
    } else {
        printf("Pilha cheia\n");
    }
}

int desempilhar(PilhaEstatica *p) {
    if (p->topo > 0) {
        p->topo--;
        return p->vetor[p->topo];
    }
    printf("Pilha vazia\n");
    return -1; // Retornar um valor de erro
}

int main() {
    PilhaEstatica p;
    p.topo = 0; 

    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);

    printf("Desempilhado: %d\n", desempilhar(&p));
    printf("Desempilhado: %d\n", desempilhar(&p));
    printf("Desempilhado: %d\n", desempilhar(&p));
    return 0;
}