#include <stdio.h>
void bubblesort(int* vet, int n) {
    for (int j = 0; j < n - 1; j++) {
        for (int i = 0; i < n - 1 - j; i++) {
            if (vet[i] > vet[i+1]) {
                int aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
            }
        }
    }
}

int main() {
    int vet[10];
    
    printf("Digite uma string: ");
    scanf("%s", str); 

   bubblesort(vet, 10);

    printf("\nVetor ordenado:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", vet[i]);
    }

    return 0;
}