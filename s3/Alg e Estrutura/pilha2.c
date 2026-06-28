#include <stdio.h>
#include <stdlib.h>

#define TAM 10

typedef struct {
    int vetor[TAM];
    int topo = 0;
} PilhaEstatica;

void empilhar(PilhaEstatica* p, int valor) {
    if (p->topo < TAM) {
        p->vetor[p->topo] = valor;
        p->topo++;
    } else
        printf("Pilha esta cheia!\n");
}

int desempilhar(PilhaEstatica* p) {
    if (p->topo > 0) {
        p->topo--;
        return p->vetor[p->topo];
    }
    return 0;
}

int main() {
    PilhaEstatica p;
    
    empilhar(&p, 10);
    empilhar(&p, 20);
    empilhar(&p, 30);
    
    printf("%d\n", desempilhar(&p));
    printf("%d\n", desempilhar(&p));
    printf("%d\n", desempilhar(&p));
    
    return 0;
}