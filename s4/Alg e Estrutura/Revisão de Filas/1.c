typedef struct No{
    int valor;
    struct No* proximo;
} No;

typedef struct Fila{
    No* inicio;
    No* fim;
}Fila;