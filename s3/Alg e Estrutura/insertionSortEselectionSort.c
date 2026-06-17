#include<stdio.h>
#include<stdlib.h>

void insertionSort(float vet[], int n) {
    for (int i = 1; i < n; i++) {
        float aux = vet[i];
        int j = i - 1;
        while (j >= 0 && vet[j] > aux) {
            vet[j + 1] = vet[j];
            j--;
        }
        vet[j + 1] = aux;
        for (int k = 0; k < n; k++) {
            printf("vet[%d]: %f \n", k, vet[k]);
        }
        printf("\n");
    }
}

void selectionSort(float vet[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (vet[j] < vet[min]) {
                min = j;
            }
        }
        float aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
        for (int k = 0; k < n; k++) {
            printf("vet[%d]: %f \n", k, vet[k]);
        }
        printf("\n");
    }
}


int main(){
    float vet[6] =  {2499.90, 1899.00, 5499.90, 999.90, 3200.00, 1500.00};
    printf("Vetor 1 original:\n");
    insertionSort(vet, 6);
    

    float vet2[6] =  {2499.90, 1899.00, 5499.90, 999.90, 3200.00, 1500.00};
    printf("Vetor 2 original:\n");
    selectionSort(vet2, 6);

    return 0;
}
    