#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct NoFila* PtrNoFila;

typedef struct NoFila{
	int chave;
	//int idade;
	PtrNoFila proximo;
} NoFila;

typedef struct{
	PtrNoFila inicio;
	PtrNoFila fim;
	int qtdElementos;
} FilaDinamica;

void iniciaFilaDinamica(FilaDinamica *f){
	f->inicio = NULL;
	f->fim = NULL;
	f->qtdElementos = 0;
}

bool estaVaziaFilaDinamica(FilaDinamica *f){
	return(f->inicio == NULL);
}

int tamanhoFilaDinamica(FilaDinamica *f){
	return f->qtdElementos;
}

void inserirFilaDinamica(FilaDinamica *f, int valor){
	PtrNoFila aux = malloc(sizeof(NoFila));
	aux->chave = valor;
	aux->proximo = NULL;
	if(estaVaziaFilaDinamica(f)){
		f->inicio = aux;
	}
	else{
		f->fim->proximo = aux;
	}
	f->fim = aux;
	f->qtdElementos++;
}

void removerFilaDinamica(FilaDinamica *f){
	if(!estaVaziaFilaDinamica(f)){
		PtrNoFila aux;
		aux = f->inicio;
		f->inicio = f->inicio->proximo;
		free(aux);
		f->qtdElementos--;
	}
	else{
		printf("Fila Vazia!\n");
		}
}

int inicioFilaDinamica(FilaDinamica *f){
	int ret = -1;
	if(!estaVaziaFilaDinamica(f)){
		ret = f->inicio->chave;
	}
	return ret;
}

int fimFilaDinamica(FilaDinamica *f){
	int ret = -1;
	if(!estaVaziaFilaDinamica(f)){
		ret = f->fim->chave;
	}
	return ret;
}

void imprimirFilaDinamica(FilaDinamica *f){
	printf("Fila[");
	PtrNoFila aux;
	for(aux=f->inicio;aux!=NULL;aux=aux->proximo){
		printf("%d ", aux->chave);
	}
	printf("]\n");
}
int main(){
	
	FilaDinamica fila;	
	iniciaFilaDinamica(&fila);
	if(estaVaziaFilaDinamica(&fila)){
		printf("Fila vazia!\n");
	int tam = tamanhoFilaDinamica(&fila);
	printf("Tamanho = %d\n", tam);
	}
	int vetor[]={5,8,9,15,21};
	int i;
	for(i=0;i<5;i++){
		inserirFilaDinamica(&fila, vetor[i]);
		imprimirFilaDinamica(&fila);
	//	printf("Tamanho = %d\n", tamanhoFilaDinamica(&fila));
	}
	for(i=0;i<5;i++){
	//	printf("Inicio = %d\n", inicioFilaDinamica(&fila));
	//	printf("Fim = %d\n", fimFilaDinamica(&fila));		
		removerFilaDinamica(&fila);
		imprimirFilaDinamica(&fila);
	}
	
	return 0;
}