#include <stdio.h>

int main(){
    char path[500];
    char output[500];
    char c, convertido;
    scanf(" %[^\n]s", path);
    scanf(" %[^\n]s", output);
   FILE *fotouau = fopen(path, "r");
   FILE *invertido = fopen(output, "w");
    if(fotouau == NULL || invertido == NULL)
        return 1;

    while((c=fgetc(fotouau)) != EOF){
        convertido = c;
        if(c == '.'){
            convertido = '#';
        }else if(c == '#'){
            convertido = '.';
        }

        fputc(convertido, invertido);
    }
    fclose(fotouau);
    fclose(invertido);
}