#define ALFABETO_TAM 26

// Estrutura:
typedef struct no {
    struct no* filhos[ALFABETO_TAM];
    int fim_palavra;
} No;

// Métodos:
No* criar_no() {
    // Implemente a criação de nós
    No* novo = (No*)malloc(sizeof(No));
    novo->fim_palavra = 0;
    for (int i = 0; i < ALFABETO_TAM; i++) {
        novo->filhos[i] = NULL;
    }
    return novo;
}

void inserir(No* raiz, const char* palavra) {
    // Implemente a inserção
    No* atual = raiz;
    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';
        if (atual->filhos[indice] == NULL) {
            atual->filhos[indice] = criar_no();
        }
        atual = atual->filhos[indice];
    }
    atual->fim_palavra = 1;
}

int buscar(No* raiz, const char* palavra) {
    // Implemente a busca
    No* atual = raiz;
    for (int i = 0; palavra[i] != '\0'; i++) {
        int indice = palavra[i] - 'a';
        if (atual->filhos[indice] == NULL) {
            return 0;
        }
        atual = atual->filhos[indice];
    }
    return atual->fim_palavra;
}