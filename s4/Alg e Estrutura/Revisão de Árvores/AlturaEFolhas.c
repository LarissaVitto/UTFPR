typedef struct AB {
    // Defina a estrutura AB
    int val;
    struct AB* esq;
    struct AB* dir;
} AB;


AB* criar_no(int valor) {
    AB* novo = (AB*)malloc(sizeof(AB));
    // Complete a implementação da instanciação do nó
    novo->val = valor;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

AB* inserir(AB* raiz, int val) {
    // Implemente a inserção
    if (raiz == NULL) {
        return criar_no(val);
    }
    if (val < raiz->val) {
        raiz->esq = inserir(raiz->esq, val);
    } else if (val > raiz->val) {
        raiz->dir = inserir(raiz->dir, val);
    }
    return raiz;
}

int contar_nos(AB *a){
    if(a == NULL){
        return 0;
    }
    return 1 + contar_nos(a->esq) + contar_nos(a->dir);
}

int contar_folhas(AB *a){
    if(a == NULL){
        return 0;
    }
    if(a->esq == NULL && a->dir == NULL){
        return 1;
    }
    return contar_folhas(a->esq) + contar_folhas(a->dir);
}