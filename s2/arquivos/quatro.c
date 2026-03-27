#include <stdio.h>
#include <string.h>

int main(){
    char path[500];
    char c;
    scanf(" %[^\n]s", path);
   FILE *arquivo = fopen(path, "r");
    if(arquivo == NULL)
        return 1;

    horizontal();
    fclose(arquivo);
}
void horizontal(FILE *arquivo){
    linha[500];
    while(fgets(linha, 500, arquivo) != NULL){
        for(int i = strlen(linha); i>= 0; i--){
            printf("%c", linha[i]);
        }
    }
};
void vertical(){

};