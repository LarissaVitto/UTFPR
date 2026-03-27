#include <stdio.h>
#include<string.h>
int main(){
    char frase[50];
    scanf("%[^\n]s", frase);
    int n = strlen(frase);
    int pa = 0;
    char *p1 = NULL;
    char *p2 = NULL;

     for(int i=0;i<n/2;i++){
        p1 = frase + i;
        p2 = frase + n - 1 - i;
            if((*p1) != (*p2)){
                pa = 0;
                break;
            }else{
                pa = 1;
            }
        }
    if(pa == 1){
        printf("\nPalindromo");
    }else{
        printf("\nn eh palindromo");
    }
}