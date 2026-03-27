#include <stdio.h>

int main(){
    char c, convertido;
    char linha[500];
    int ascii = 222;
   FILE *criptografado = fopen("criptografado.txt", "r");
    FILE *descriptografado = fopen("descriptografado.txt", "w");
    if(criptografado == NULL || descriptografado == NULL)
        return 1;

    while((c=fgetc(criptografado)) != EOF){
        convertido = c - ascii;
    }

    fputc(convertido, descriptografado);

    while((fgets(linha, 500, descriptografado)) != NULL){
        printf("%s", linha);
    }

    fclose(criptografado);
}