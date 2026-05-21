#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoa{
    char nome[20];
    int idade;
}Pessoa;

typedef struct no {
    Pessoa pessoa;
    struct no* prox;
} no;

typedef struct Fila {
    no* primeiro;
    no* ultimo;
}Fila;

void iniciaFila(Fila *f) {
    f->primeiro = NULL;
    f->ultimo = NULL;
}

void Enqueue(Fila* f, Pessoa pessoa) { // enfileirar
    no* novoNo = (no*)malloc(sizeof(no));
    novoNo->pessoa = pessoa;
    novoNo->prox = NULL;
    if (f->ultimo != NULL) {
        f->ultimo->prox = novoNo;
    } else {
        f->primeiro = novoNo;
    }
    f->ultimo = novoNo;
}

void Dequeue(Fila* f) { // desenfileirar
    if (f->primeiro != NULL) {
        no* aux = f->primeiro;
        f->primeiro = f->primeiro->prox;
        free(aux);
    } else {
        f->ultimo = NULL;
        printf("Fila vazia\n");
    }
}

void printar(Fila *f) {
    if (f->primeiro != NULL) {
        no* aux = f->primeiro;
        while (aux != NULL) {
            printf("[%s]\n", aux->pessoa.nome);
            aux = aux->prox;
        }
    } else {
        printf("Fila vazia.\n");
    }
}

void ordenar(Fila* f){
    if (f->primeiro != NULL) {
        no* aux1 = f->primeiro;
        while (aux1 != NULL) {
            no* aux2 = aux1->prox;
            while (aux2 != NULL) {
                if (aux1->pessoa.idade < aux2->pessoa.idade) {
                    Pessoa teste = aux1->pessoa;
                    aux1->pessoa = aux2->pessoa;
                    aux2->pessoa = teste;
                }
                aux2 = aux2->prox;
            }
            aux1 = aux1->prox;
        }
    } else {
        printf("Fila vazia.\n");
    }
}

int main() {
    Fila f1; 
    Pessoa p1, p2, p3;
    strcpy(p1.nome, "Pessoa 20 anos");
    p1.idade = 20;
    strcpy(p2.nome, "Pessoa 25 anos");
    p2.idade = 25;
    strcpy(p3.nome, "Pessoa 30 anos");
    p3.idade = 30;

    iniciaFila(&f1); 

    Enqueue(&f1, p1);
    Enqueue(&f1, p2);
    Enqueue(&f1, p3);
    printar(&f1);
    printf("Ordenar mais velhos primeiro\n");
    ordenar(&f1);
    printar(&f1);
    Dequeue(&f1); 
    Dequeue(&f1);
    printf("Verificar apos sobrar 1\n"); 
    printar(&f1);
    Dequeue(&f1); 
    Dequeue(&f1); //verificar se ta certo
    printar(&f1);
    return 0;
}