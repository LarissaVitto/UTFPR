#include <stdio.h>
#include <string.h>
int main(){
    char frase[10];
    int count;
    scanf("%[^\n]", frase);
    count = strlen(frase);
    for(int i = 0; i < count; i++){
        printf("%c\n", frase[i]);
    }
    return 0;
}