#include <stdio.h>
int soma_fat(int x);
int main() {
    int i, n, x;
    scanf("%i", &n);
    for (i = 0; i < n; i++) {
        scanf("%i", &x);
        printf("%i\n", soma_fat(x));
    }
}
int soma_fat(int x){
    int RESULTADO = 0;
    int contando = x, xx = x - 1;
    for(int i = 1; i < contando; i++){
        RESULTADO = x * xx;
        x = RESULTADO;
        xx--;
    }
    return(RESULTADO);
}
/*int fatoracao(int x) { moodle
    int resultado = 1;
    for (int i = 1; i <= x; i++) {
        resultado *= i;
    }
    return resultado;
}
int soma_fat(int x) {
    int soma = 0;
    for (int i = 1; i <= x; i++) {
        soma += fatoracao(i);
    }
    return soma;
}*/