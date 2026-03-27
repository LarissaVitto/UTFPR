#include<stdio.h>
int main(){
  int n;
  printf("\nTamanho do vetor: ");
  scanf("%d",&n);
  int numeros[n], *ptr;
  ptr = numeros;
      

  for(int i=0;i<n;i++){
    printf("\nv[%d]: ", i);
    scanf("%d", &numeros[i]);
  }

  for(;ptr <= &numeros[n-1];ptr++){
    printf(" %d",*(ptr));
  }
  printf("\n");
  return 0;
}