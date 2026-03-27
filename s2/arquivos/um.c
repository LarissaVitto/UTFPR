#include <stdio.h>

int main(){
    char path[500];
    char c;
    int cont = 0;
    scanf(" %[^\n]s", path);
   // FILE *arquivo = fopen("teste.txt", "r"); seila
   FILE *arquivo = fopen(path, "r");
    if(arquivo == NULL)
        return 1;

    while((c=fgetc(arquivo)) != EOF){
        if(c == '\n'){
            cont++;
        }
    }
 
   /* for(int i = 0; arquivo =! EOF; i++){
        *arquivo ++;
    } da pra fz com for mas o teruo disse q eh melhor com while se nao fica mt grande*/

    printf("qtd de quebra de linhas: %d", cont);
    fclose(arquivo);
}