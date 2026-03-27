#include <stdio.h>
int soma(int A, int B);
int main() {
    int A = 0, B = 0;
    int N = 0;
    scanf("%d", &N);
     for(int i = 0; i < N; i++){
        scanf("%d %d", &A, &B);
        printf("%i\n", soma(A, B));
    }
    return 0;
}
int soma(int A, int B){
    return (A + B);
}

/*#include <stdio.h> moodle
void soma(){
    int A = 0, B = 0;
    int N = 0;
    scanf("%d", &N);
     for(int i = 0; i < N; i++){
        scanf("%d %d", &A, &B);
        printf("%d\n", A + B);
    }
}*/