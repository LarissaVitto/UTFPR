#include <stdio.h>
int main(){
    int X, Y, Z, W;
    scanf("%d %d %d %d", &X, &Y, &Z, &W);
    if(X == Y || Z != W){
        printf("Resultado: Ao menos uma expressão é VERDADEIRA");
    }else{
        printf("Resultado: Todas as expressões são FALSAS");
    }
    return 0;
}