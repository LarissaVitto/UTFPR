typedef struct No {
    int chave; // valor ou char
    struct No *esq, *dir;
} No;

No* criar_no(int chave) {
    No* n = (No*) malloc(sizeof(No));
    n->chave = chave; 
    n->esq = n->dir = NULL;
    return n;
}

int calcular(No* raiz) {
    // Implemente a analise da expressão
    if (raiz->esq == NULL && raiz->dir == NULL) {
        return raiz->chave;
    }
    if (raiz->chave != '+' && raiz->chave != '-' && raiz->chave != '*' && raiz->chave != '/') {
        return calcular(raiz->esq) + calcular(raiz->dir);
    }

    int esquerda = calcular(raiz->esq);
    int direita = calcular(raiz->dir);

    switch (raiz->chave) {
        case '+':
            return esquerda + direita;

        case '-':
            return esquerda - direita;

        case '*':
            return esquerda * direita;

        case '/':
            return esquerda / direita;
    }
        return -1;
}

// Funcao fornecida para ler notacao prefixa (Ex: * + 5 2 3)
No* ler_prefixa(char* token) {
    if (strlen(token) == 1 && (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/')) {
        No* op = criar_no((int) *token);
        
        token = strtok(NULL, " \n");
        op->esq = ler_prefixa(token);
        token = strtok(NULL, " \n");
        op->dir = ler_prefixa(token);
        return op;
    } else {
        return criar_no(atoi(token));
    }
}
  
// Percurso em-ordem (com parênteses)
void emOrdem(No* r) {
    if (r != NULL) {
        if (r->esq != NULL) printf("(");
        emOrdem(r->esq);
        if (r->esq != NULL) printf(" %c ", r->chave);
        else printf(" %d ", r->chave);
        emOrdem(r->dir);
        if (r->dir != NULL) printf(")");
    }
}