#include <stdio.h>
int multiplicacao(int A, int B);
int main() {
    int n, a, b;
    scanf("%d", &n);
    for (int i=0; i<n; i++){
        scanf("%d%d", &a, &b);
        printf("%d\n", multiplicacao(a,b));
    }
    return 0;
}
int multiplicacao(int A, int B){//moodle só aq
    return (A * B);
}