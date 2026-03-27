void printMatriz(int linhas, int colunas, int matriz[3][3]){
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int processaMatriz(int linhas, int colunas, int x, int matriz[3][3]){
    int count = 0;
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            if (matriz[i][j] > x){
                matriz[i][j] = 0;
                count++;
            }
        }
    }
    return count;
}