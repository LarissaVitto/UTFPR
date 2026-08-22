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
void push(Pilha* p, No* no) {
    no->proximo = p->topo;
    p->topo = no;
}

// Método Pop (desempilhar)
int pop(Pilha *p) {
    if (p->topo == NULL) {
        return -1;   // falha
    }
    
    int valorRemovido;

    No *aux = p->topo;
    valorRemovido = aux->valor;
    p->topo = aux->proximo;
    free(aux);

    return valorRemovido;       // sucesso
}

// Método para imprimir a Pilha
void imprimir(Pilha* p){
    No *aux = p->topo;
    while(aux != NULL){
        printf("%d\n", aux -> valor);
        aux = aux -> proximo;
    }
}