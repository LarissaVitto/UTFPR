#include <stdio.h>

int main(){
    char linha[500];
   FILE *fotouau = fopen("img.txt", "r");
    if(fotouau == NULL)
        return 1;

    while((fgets(linha, 500, fotouau)) != NULL){
        printf("%s", linha);
    }

    fclose(fotouau);
}