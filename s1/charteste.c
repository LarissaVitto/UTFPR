#include <stdio.h>
int main(){
    char nota;
    scanf("%c", &nota);
    if(nota == 'A' || nota == 'a'){
        printf("Excelente! Parabens!");
    }else if(nota == 'B' || nota == 'C' || nota == 'b' || nota == 'c'){
        printf("Voce foi bem.");   
    }else if(nota == 'D' || nota == 'd'){
        printf("Foi por muito pouco!");
    }else if(nota == 'F' || nota == 'f'){
        printf("Estudar mais na proxima.");
    }else{
        printf("Valor invalido.");
    }
}