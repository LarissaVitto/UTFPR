#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Node {
    int id;
    struct Node* left;
    struct Node* right;
} Node;

Node* criar_no(int id) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->id = id;
    novo->left = NULL;
    novo->right = NULL;
    return novo;
}

Node* inserir(Node* root, int id) {
    if (root == NULL) return criar_no(id);
    if (id < root->id) 
        root->left = inserir(root->left, id);
    else 
        root->right = inserir(root->right, id);
    return root;
}

int buscar(Node* root, int id) {
    while (root != NULL) { //abordagem iterativa, utilizando um loop while
        if (root->id == id) {
            printf("Sensor %d encontrado!\n", id); //printf adicionado para melhor visualização do resultado
            return 1;
        }
        if (id < root->id) {
            root = root->left; 
        } else {
            root = root->right;
        }
    }
    return 0;
}

int main() {
    Node* raiz = NULL;
    int i, tamanho = 30000; 
    int *valores = (int *)malloc(tamanho * sizeof(int));

    for (i = 0; i < tamanho; i++) {  //preenche o vetor
        valores[i] = i + 1;
    }

    srand(time(NULL));
    
    for (i = tamanho - 1; i > 0; i--) { // Estratégia na main para embaralhar o vetor com a biblioteca time.h (Fisher-Yates)
        int j = rand() % (i + 1);
        int temp = valores[i];
        valores[i] = valores[j];
        valores[j] = temp;
    }

    printf("Populando a Arvore de Sensores...\n");
    for (i = 0; i < tamanho; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Buscando o ultimo sensor...\n");
    clock_t inicio = clock();
    
    int encontrado = buscar(raiz, valores[tamanho - 1]); 
    
    clock_t fim = clock();
    double tempo = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Resultado da busca: %d em %.5f segundos\n", encontrado, tempo);
    return 0;
}
