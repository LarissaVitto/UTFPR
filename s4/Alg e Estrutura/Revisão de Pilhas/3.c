typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *topo;
} Pilha;

// Método de criação da Pilha
Pilha* criarPilha() {
    Pilha *p = (Pilha *) malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

// Método de criação do Nó
No* criarNo(int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

// Método Push (empilhar)
void push(Pilha* p, No* novo){
    novo -> proximo = p -> topo; //como o criar no retorna o novo o topo é o novo e o push ja recebe o
    p -> topo = novo;            // novo no pq passa junto com a função criarNo
}