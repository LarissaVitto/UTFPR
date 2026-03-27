#include <stdio.h>
int main(){
    int idade;
    scanf("%d", &idade);
    if(idade >= 18 && idade <= 65){
        printf("Idade valida");
    }else{
        printf("Idade invalida");
    }
    return 0;
}