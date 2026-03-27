#include <stdio.h>

int main() {
    int idade, vezes, kg;
    char gen;
    scanf("%d %d %c %d", &idade, &kg, &gen, &vezes);
    if ((gen == 'f' || gen == 'F') || (gen == 'm' || gen == 'M')) {
        if (idade >= 18 && idade <= 72 && kg >= 42) {
            if ((gen == 'f' || gen == 'F') && vezes <= 4) {
                printf("Pode ser doador");
            } else if ((gen == 'm' || gen == 'M') && vezes <= 3) {
                printf("Pode ser doador");
            } else {
                printf("Nao pode ser doador");
            }
        } else {
            printf("Nao pode ser doador");
        }
    } else {
        printf("Genero invalido");
    }
    return 0;
}
