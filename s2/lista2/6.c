#include <stdio.h>
int multiplica(int c, int x);
int cubo(int x);
int quadrado(int x);
int pol_cubo(int a, int b, int c, int d, int x)
int main() {
    int i, n;
    int  a, b, c, d, x;
        
    scanf("%i", &n);
    for (i = 0; i < n; i++) {
        scanf("%i %i %i %i %i", &a, &b, &c, &d, &x);
        printf("%i %i %i %i\n", cubo(x), quadrado(x), multiplica(c,x), pol_cubo(a, b, c, d, x));
    }
    return 0;
}
int multiplica(int c, int x){
    return (c * x);
}
int cubo(int x){
    return (x * x * x);
}
int quadrado(int x){
    return (x * x);
}
int pol_cubo(int a, int b, int c, int d, int x){
    return (a* cubo(x) + b * quadrado(x) + c * x + d);
}