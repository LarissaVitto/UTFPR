#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void bubbleSort(int n, char v[n]){
  char* p1 = NULL;
  char* p2 = NULL;
  n = strlen(v);
  for(int i=0; i<n; i++){
    p1 = v + i;
    for(int j=0;j<n; j++){
      p2 = v + j;
      if((*p2)>(*p1)){
        char aux = *p2;
        *p2 = *p1;
        *p1 = aux;
      }
    }
  }
}

int main(){
  int n = 100; 
  char texto[100] = "String utilizada como teste para o algoritmo de ordenacao.";
  printf("\nOriginal: %s\n", texto);
  bubbleSort(n, texto);
  printf("\nOrdenado: %s\n", texto);
  return 0;
}
