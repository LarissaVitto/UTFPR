#include<stdio.h>
#include<stdlib.h>

typedef struct NoLista* PtrNoLista;

typedef struct NoLista {
    int valor;
    ptrNoLista* prox;
}NoLista;

typedef struct{
    PtrNoLista inicio;
}Lista;//dinamica

NoLista* criarNo(int valor){
    Nolista* novoNo = (NoLista*)malloc(sizeof(NoLista));
    novoNo -> valor = valor;
    novoNo -> prox = NULL;
    return novoNo;
} 

void iniciaLista(Lista *Lista){
    Lista* Inicio = (Lista*)malloc(sizeof(Lista));
    Lista->inicio = NULL;
    return Lista;
}

void inserir(Lista *Lista, int valor;){
    if(Lista->inicio == NULL){
        Lista->inicio = criarNo(valor);
    } else {
        PtrNoLista aux = Lista->inicio;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = criarNo(valor);
    }
    PtrNoLista aux = malloc(sizeof(NoLista));
    aux->valor = valor;
    aux->prox = NULL;
}

int comparar(Lista *L1, Lista *L2){
    NoLista* aux1 = L1->inicio;
    NoLista* aux2 = L2->inicio;

    while(aux1 != NULL && aux2 != NULL){
        aux1 = aux1->prox;
        aux2 = aux2->prox;
    }
    return(aux1 == NULL && aux2 == NULL);
}
int main(){
    Lista* L1 = iniciaLista();
    Lista* L2 = iniciaLista();

    inserir(L1, 2);
    inserir(L1, 3);
    inserir(L1, 4);

    inserir(L2, 1);
    inserir(L2, 3);
    inserir(L2, 5);
    inserir(L2, 6);

    if(comparar(&L1, &L2)){
        printf("As listas sao do mesmo tamanho!\n");
    } else {
        printf("As listas sao diferentes!\n");
    }
    return 0;
}