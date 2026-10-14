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

// Inserção em BST
No* inserir(No* raiz, int valor) {
    if (raiz == NULL) return novo_no(valor);

    if (valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);
    else
        raiz->dir = inserir(raiz->dir, valor);
    return raiz;
}

// Altura
int calcular_altura(No* raiz) {
    if (raiz == NULL){
        return 0;        
    }
    
    int altura_esq = calcular_altura(raiz->esq);
    int altura_dir = calcular_altura(raiz->dir);

    if (altura_esq > altura_dir){
        return altura_esq + 1;
    }else{
        return altura_dir + 1;
    }
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
    // Caso 1: Inserção balanceada
    // =========================
    No* ab = NULL;

    int v1[] = {5, 2, 1, 3, 4, 8, 6, 7, 9};
    for (int i = 0; i < 10; i++) ab = inserir(ab, v1[i]);

    int altura_1 = calcular_altura(ab);
    liberar(ab);

    // =========================
    // Caso 2: Inserção crescente
    // =========================
    ab = NULL;

    int v2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 10; i++) ab = inserir(ab, v2[i]);

    int altura_2 = calcular_altura(ab);
    liberar(ab);

    // =========================
    // Resultados
    // =========================
    ab = NULL;
    printf("Altura (vazia): %d\n", calcular_altura(ab));
    printf("Altura (insercao balanceada): %d\n", altura_1);
    printf("Altura (insercao crescente): %d\n", altura_2);

    return 0;
}