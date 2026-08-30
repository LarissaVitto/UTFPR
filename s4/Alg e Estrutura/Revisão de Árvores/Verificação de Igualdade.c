typedef struct No {
    int chave;
    struct No *esquerda, *direita;
} No;

No* criar_no(int chave) {
    No* n = (No*)malloc(sizeof(No));
    n->chave = chave; 
    n->esquerda = n->direita = NULL;
    return n;
}

No* inserir(No* raiz, int chave) {
    if (!raiz){
        return criar_no(chave);
    }
    if (chave < raiz->chave) 
        raiz->esquerda = inserir(raiz->esquerda, chave);
    else 
        raiz->direita = inserir(raiz->direita, chave);
    return raiz;
}

int iguais(No* raiz_a, No* raiz_b) {
    // implemente a comparação aqui
    if (raiz_a == raiz_b){
        return 1; 
    }
    if (!raiz_a || !raiz_b){
        return 0;
    }
    if (raiz_a->chave != raiz_b->chave){
        return 0;
    }
    return iguais(raiz_a->esquerda, raiz_b->esquerda) && iguais(raiz_a->direita, raiz_b->direita);
}