typedef struct No {
    int valor;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
} Fila;

// Verifica se a Fila está vazia:
int filaVazia(Fila *f) {
    return f->inicio == NULL;
}

// Método de criação da Fila
Fila* criarFila() {
    Fila *f = (Fila*)malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

// Método de criação do Nó
No* criarNo(int valor) {
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}
