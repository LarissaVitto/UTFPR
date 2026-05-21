#include<stdio.h>
#include<stdlib.h>

typedef struct Pessoa{
    char nome[50];
    int idade;

    struct Pessoa* proximo;
}Pessoa;

typedef struct{
    Pessoa* inicio;
    Pessoa* fim;
}FilaPessoa;

FilaPessoa* criarFila(){
    FilaPessoa* novaFila = (FilaPessoa*)malloc(sizeof(FilaPessoa));
    novaFila->inicio = NULL;
    novaFila->fim = NULL;
    return novaFila;
}

Pessoa* criarPessoa(char* nome, int idade){
    Pessoa* novaPessoa = (Pessoa*)malloc(sizeof(Pessoa));
    //strcpy(novaPessoa->nome, nome);
    novaPessoa->idade = idade;
    novaPessoa->proximo = NULL;
    return novaPessoa;
}

void enfileirar(FilaPessoa* fila, char*, Pessoa* novaPessoa){
    Pessoa* novaPessoa = criarPessoa(nome, idade);
    if(fila->inicio == NULL){
        fila->inicio = novaPessoa;
        fila->fim = novaPessoa;
    } else {
        fila->fim->proximo = novaPessoa;
        fila->fim = novaPessoa;
    }
}

Pessoa* desenfileirar(FilaPessoa* fila){
    if(fila->inicio == NULL){
        printf("Fila Vazia!\n");
        return NULL;
    }
    Pessoa* pessoaRemovida = fila->inicio;
    //fila->inicio = fila->inicio->proximo; pensa q vai abrindo as aba uma por uma assim fica mais facil
    fila->inicio = pessoaRemovida->proximo; //virou pessoaremovida pq já é os 2

   // free(pessoaRemovida); n usou
    return pessoaRemovida;
}

int main(){
    FilaPessoa* fila = criarFila();
    Pessoa* p1 = criarPessoa("Joao", 30);
    Pessoa* p2 = criarPessoa("Maria", 23);
    enfileirar(fila, p1);
    enfileirar(fila, p2);
    return 0;
}
    