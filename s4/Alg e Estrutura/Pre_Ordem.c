// implemente a estrutura aqui.
typedef struct no{
    int chave;
    struct no *esquerda;
    struct no *direita;
}No;

No* criaNoArvore(int chave){
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}


No* criar_no(int chave) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->chave = chave;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, int chave) {
    if(raiz == NULL){
        return criaNoArvore(chave);
    }else if(chave < raiz->chave){
        raiz->esquerda = inserir(raiz->esquerda, chave); 
    }else{
        raiz->direita = inserir(raiz->direita, chave);
    }
    return raiz;
}

// Implemente a visitação em pré-ordem:
void pre_ordem(No* raiz){ //Pré-ordem
    if(raiz != NULL){
        printf("%d ", raiz->chave);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}