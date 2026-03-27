#include <stdio.h>
int Imprime(int N);
int main(){
    int N;
    scanf("%d", &N);
    Imprime(N);
    return 0;
}
int Imprime(int N){
    for(int i = 0; i < N; i++){
        printf("Executado\n");
    }
    return 0;
}
/* moodle
#include <stdio.h>
int print(int N){
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        printf("Executado\n");
    }
    return 0;
}*/