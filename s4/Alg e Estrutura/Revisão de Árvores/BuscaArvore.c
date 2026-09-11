typedef struct No {
    int chave;
    struct No *esquerda;
    struct No *direita;
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if(novo) {
        novo->chave = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;
    }
    return novo;
}

No* inserir_arvore(No* raiz, int valor) {
    if (raiz == NULL) {
        return criar_no(valor);
    }
    
    if (valor <= raiz->chave) {
        raiz->esquerda = inserir_arvore(raiz->esquerda, valor);
    } else {
        raiz->direita = inserir_arvore(raiz->direita, valor);
    }
    
    return raiz;
}

// Implemente a busca aqui
int buscar(No* raiz, int valor){
    if(raiz == NULL){
        return 0;
    }
    if (valor == raiz->chave) {
        return 1;
    }
    if (valor < raiz->chave) {
        return buscar(raiz->esquerda, valor);
    } else {
        return buscar(raiz->direita, valor);
    }
}