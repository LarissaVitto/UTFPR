typedef struct No {
    int chave;
    struct No *esquerda, *direita;
} No;

No* criar_no(int chave) {
    No* novo = (No*)malloc(sizeof(No));
    novo->chave = chave;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int chave) {
    if (raiz == NULL) {
        return criar_no(chave);
    }
    if (chave < raiz->chave) {
        raiz->esquerda = inserir(raiz->esquerda, chave);
    } else {
        raiz->direita = inserir(raiz->direita, chave);
    }
    return raiz;
}

// Implemente a visitação em em-ordem:
void em_ordem(No* raiz){
    if(raiz != NULL){
        em_ordem(raiz->esquerda);
        printf("%d ", raiz->chave);
        em_ordem(raiz->direita);
    }    
}