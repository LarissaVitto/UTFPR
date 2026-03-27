#include <stdio.h>
int main(){
    int A, B, C, D;
    scanf("%d %d %d %d", &A, &B, &C, &D);
    if(A > B && C > D){
        printf("Valores aprovados\n");
    }else{
        printf("Valores reprovados\n");
    }
    return 0;
}