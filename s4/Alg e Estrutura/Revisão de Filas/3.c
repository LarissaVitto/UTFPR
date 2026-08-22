typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct Fila{
    No *inicio;
    No *fim;
} Fila;

// Verifica se a Fila está vazia:
int filaVazia(Fila *f) {
    return f->inicio == NULL;
}

// Método de criação da Fila
Fila* criarFila() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

// Método de criação do Nó
No* criarNo(int valor) {
    No *novo = (No *) malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

// Método enqueue (enfileirar)
void enqueue(Fila *f, No* novo) {
    if (filaVazia(f)) {
        f->inicio = novo;
        f->fim = novo;
    }else{
        f->fim->proximo = novo;
        f->fim = novo;
    }
}

// Método dequeue (desenfileirar)
int dequeue(Fila *f) {
    if (filaVazia(f)) {
        return -1;
    }
    No *aux = f->inicio;
    int valor = aux->valor;
    f->inicio = f->inicio->proximo;
    free(aux);
    return valor;
}