void troca(int *a, int *b){
    int guarda;
    guarda = *a;
    *a = *b;
    *b = guarda;
}