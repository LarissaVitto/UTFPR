#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esq;
    struct No* dir;
} No;

// Cria novo nó
No* novo_no(int valor) {
    No* n = (No*) malloc(sizeof(No));
    n->valor = valor;
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

// Função auxiliar max
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Altura
int calcular_altura(No* raiz) {
    if (raiz == NULL) return 0;
    return 1 + max(calcular_altura(raiz->esq), calcular_altura(raiz->dir));
}

// Rotação à direita (LL)
No* rotacao_direita(No* y) {
    No* f_esq = y->esq;
    No* subarv = f_esq->dir;

    f_esq->dir = y;
    y->esq = subarv;

    return f_esq;
}

// Rotação à esquerda (RR)
No* rotacao_esquerda(No* x) {
    No* f_dir = x->dir;
    No* subarv = f_dir->esq;

    f_dir->esq = x;
    x->dir = subarv;

    return f_dir;
}

// Inserção AVL
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return novo_no(valor);
    }

    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    } else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    } else {
        return raiz;
    }

    int alt_esq = calcular_altura(raiz->esq);
    int alt_dir = calcular_altura(raiz->dir);
    int fb = alt_esq - alt_dir;

    // LL
    if (fb > 1 && valor < raiz->esq->valor) {
        return rotacao_direita(raiz);
    }
    // RR
    if (fb < -1 && valor > raiz->dir->valor) {
        return rotacao_esquerda(raiz);
    }
    // LR
    if (fb > 1 && valor > raiz->esq->valor) {
        raiz->esq = rotacao_esquerda(raiz->esq);
        return rotacao_direita(raiz);
    }
    // RL
    if (fb < -1 && valor < raiz->dir->valor) {
        raiz->dir = rotacao_direita(raiz->dir);
        return rotacao_esquerda(raiz);
    }

    return raiz;
}

// Libera memória
void liberar(No* raiz) {
    if (raiz == NULL) return;
    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz);
}

int main() {
    // =========================
    // Caso 1: Inserção "balanceada"
    // =========================
    No* ab = NULL;

    int v1[] = {5, 2, 1, 3, 4, 8, 6, 7, 9};
    for (int i = 0; i < 9; i++) ab = inserir(ab, v1[i]);

    int altura_1 = calcular_altura(ab);
    liberar(ab);

    // =========================
    // Caso 2: Inserção crescente
    // =========================
    ab = NULL;

    int v2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 9; i++) ab = inserir(ab, v2[i]);

    int altura_2 = calcular_altura(ab);
    liberar(ab);

    // =========================
    // Resultados
    // =========================
    ab = NULL;
    printf("Altura (vazia): %d\n", calcular_altura(ab));
    printf("Altura (insercao 'balanceada'): %d\n", altura_1);
    printf("Altura (insercao crescente): %d\n", altura_2);

    return 0;
}