#include <stdio.h>
#include <stdlib.h>

typedef struct Fila{
    Pessoa *inicio;
    Pessoa *fim;
} Fila;

typedef struct Pessoa {
    char nome[50];
    char senha[50];
    struct Pessoa *proximo;
} Pessoa;

Pessoa* criarPessoa(char nome, char senha) {
    Pessoa *nova = (Pessoa *) malloc(sizeof(Pessoa));
    strcpy(nova->nome, nome);
    strcpy(nova->senha, senha);
    nova->proximo = NULL;
    return nova;
}

Fila* criarFila() {
    Fila *f = (Fila *) malloc(sizeof(Fila));
    f->inicio = NULL;
    f->fim = NULL;
    return f;
}

void enfileirar(Fila *f, Pessoa *p){
    if(f->fim == NULL){
        f->inicio = p;
    }else{
        f->fim->proximo = p;
    }
    f->fim = p;
}01

int main (){
    
    return 0;
}