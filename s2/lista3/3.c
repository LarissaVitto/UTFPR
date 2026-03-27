void inverter(int n, int vet[]){
    int vet2;
    for(int i = 0; i < n/2; i++){
        vet2 = vet[i];
        vet[i] = vet[n - 1 - i];
        vet[n - 1 - i] = vet2;
    }
}

void printVetor(int n, int vet[]){
    for(int i = 0; i < n; i++){
        printf("%d ", vet[i]);
    }
    printf("\n");
}