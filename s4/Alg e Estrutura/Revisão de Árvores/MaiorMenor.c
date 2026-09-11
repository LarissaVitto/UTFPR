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

int encontrar_maior(AB *a) {
    // Implemente a busca pelo maior
    if (a == NULL) {
        return -1; // Retorna -1 se a árvore estiver vazia
    }
    if (a->dir == NULL) {
        return a->val;
    }
    return encontrar_maior(a->dir);
}

int encontrar_menor(AB *a) {
    // Implemente a busca pelo menor
    if (a == NULL) {
        return -1; // Retorna -1 se a árvore estiver vazia
    }
    if (a->esq == NULL) {
        return a->val;
    }
    return encontrar_menor(a->esq);
}