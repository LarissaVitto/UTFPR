#include <stdio.h>

void merge(int vet[], int inicio, int meio, int fim) {
    int esquerda = inicio;
    int direita = meio + 1;
    int i = 0;
    int vetAux[fim - inicio + 1];

    while (esquerda <= meio && direita <= fim) { //enquanto ainda tiver elementos na direita e na esquerda

        if (vet[esquerda] <= vet[direita]) {
            vetAux[i] = vet[esquerda];
            esquerda++;
        } else {                                //Verifica o menor pra colocar no vetor auxiliar
            vetAux[i] = vet[direita];
            direita++;
        }
        i++; 
    }

    while (esquerda <= meio) { // se sobrou na esquerda copia pro auxiliar
        vetAux[i] = vet[esquerda];
        esquerda++;
        i++;
    }
    while (direita <= fim) { // se sobrou na direita copia pro auxiliar
        vetAux[i] = vet[direita];
        direita++;
        i++;
    }

    for (int i = inicio, j = 0; i <= fim; i++, j++) { //copia o vetor auxiliar pro original
        vet[i] = vetAux[j];
    }
}

void mergeSort(int vet[], int inicio, int fim) {

    if (inicio < fim) { 
        int meio = (inicio + fim) / 2; 
        mergeSort(vet, inicio, meio); // Ordena a esquerda
        mergeSort(vet, meio + 1, fim); // Ordena a direita        
        merge(vet, inicio, meio, fim); // Junta as duas
    }
}

int main() {
    int vet[] = {8, 3, 5, 1, 9, 2, 7};
    int n = sizeof(vet) / sizeof(vet[0]);

    mergeSort(vet, 0, n - 1);

    for (int i = 0; i < n; i++) {
        printf("%d ", vet[i]);
    }
    
    return 0;
}