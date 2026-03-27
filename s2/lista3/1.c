#include <stdio.h>
int contador = 0;
int incrementarValor(int numero) {
    numero = numero + 1;
    contador++;
    return numero;
}

int main() {
    int resultado, valor;

    printf("Digite um valor: ");
    scanf("%d", &valor);
    resultado = incrementarValor(valor);
    printf("Resultado: %d\n", resultado);

    printf("Digite um valor: ");
    scanf("%d", &valor);
    resultado = incrementarValor(valor);
    printf("Resultado: %d\n", resultado);

    printf("Digite um valor: ");
    scanf("%d", &valor);
    resultado = incrementarValor(valor);
    printf("Resultado: %d\n", resultado);

    printf("A função foi chamada %d vezes.\n", contador);

    return 0;
}
