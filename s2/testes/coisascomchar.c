#include<stdio.h>
#include<stdlib.h>

char* buscar(char letra, char* texto);
void imprimir(char* texto, char* inicio);

int main(){
  char letra;
  printf("\nQual letra deseja buscar? ");
  scanf("%c", &letra);
  char* frase = "Buscando uma letra no meio de um texto";
  printf("\n%s\n", frase);
  char* p = buscar(letra, frase);
  if(p!=NULL){
    imprimir(frase, p);
  }else
    printf("\nNao encontrado!\n");
  return 0;
}

char* buscar(char letra, char* texto){

}

void imprimir(char* texto, char* inicio){

}

int main(){
  char letra;
  printf("\nQual letra deseja buscar? ");
  scanf("%c", &letra);
  char* frase = "Buscando uma letra no meio de um texto";
  printf("\n%s\n", frase);
  char* p = buscar(letra, frase);
  if(p!=NULL){
    imprimir(frase, p);
  }else
    printf("\nNao encontrado!\n");
  return 0;
}