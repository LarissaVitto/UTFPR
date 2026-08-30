typedef struct No {
    char nome[50];
    struct No *esquerda, *direita;
} No;

No* criar_no(char* s) {
    No* novo = (No*)malloc(sizeof(No));
    strcpy(novo->nome, s);
    novo->esquerda = novo->direita = NULL;
    return novo;
}

No* inserir_nome(No* raiz, char* nome) {
    // Utilize strcmp
    if (!raiz){
        return criar_no(nome);
    }
    if (strcmp(nome, raiz->nome)  < strcmp(raiz->nome, nome)){
        raiz->esquerda = inserir_nome(raiz->esquerda, nome); //verifica se o nome é menor doq a raiz
    }else{
        raiz->direita = inserir_nome(raiz->direita, nome);
    }
    return raiz;
}

void em_ordem_nomes(No* raiz) {
    // Imprima os nomes em_ordem
    if (raiz){
        em_ordem_nomes(raiz->esquerda);
        printf("%s\n", raiz->nome);
        em_ordem_nomes(raiz->direita);
    }
}