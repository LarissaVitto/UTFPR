#include <stdio.h>

void quickSort(int vet[], int inicio, int fim) {
    if (inicio >= fim)
        return;

    int esq = inicio;
    int dir = fim;
    int pivo = vet[inicio];

    while (esq < dir) {
        while (esq <= fim && vet[esq] <= pivo) //PARA qnd é maior q o pivo e tiver na esquerda
            esq++;

        while (vet[dir] > pivo) //PARA qnd é menor q o pivo e tiver na direita 
            dir--;

        if (esq < dir) { // dai dps q para os da direita e da esquerda eles trocam de lugar 
            int aux = vet[esq]; // aí fica os maior na frente e os menor atrás
            vet[esq] = vet[dir];
            vet[dir] = aux;
        }
    }

    vet[inicio] = vet[dir]; //qnd a direita e a esquerda fica no mesmo, coloca o pivô lá
    vet[dir] = pivo;

    quickSort(vet, inicio, dir - 1);  //dai aqui ele chama pra esquerda
    quickSort(vet, dir + 1, fim); // e aqui pra direita
}

int main() {
    int vet[] = {8, 3, 5, 1, 9, 2, 7};
    int n = sizeof(vet) / sizeof(vet[0]);

    quickSort(vet, 0, n - 1);

    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);

    return 0;
}