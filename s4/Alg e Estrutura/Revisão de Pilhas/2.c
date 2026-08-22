typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

// Método de criação da Pilha
Pilha *criarPilha(){
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

// Método de criação do Nó
No* criarNo(char valor){
    No *n = (No*) malloc(sizeof(No));
    n->valor = valor;
    n->proximo = NULL;
    return n;
}