// ---------- ESTRUTURA DE NÓ ----------
// Estrutura "No" com "valor" numérico e ponteiro "proximo", 
// para ser usado com a pilha ou fila:
// ...
typedef struct no{
    int valor;
    struct no* prox;
}no;
// ---------- ESTRUTURA DE FILA ----------
// Estrutura "Fila": 
// ...
typedef struct Fila{
    no* primeiro;
    no* ultimo;
    int qtdElementos;
}Fila;
// Inicializa fila
Fila* criaFila() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    if (f != NULL) {
        f->primeiro = NULL;
        f->ultimo = NULL;
        f->qtdElementos = 0;
    }
    return f;
}

// Verifica se fila está vazia
int filaVazia(Fila* f) {
    if (f->qtdElementos == 0){
        return 1; 
    }
    return 0;
}

// Enfileirar
void enfileirar(Fila* f, int valor) {
    no* aux = (no*)malloc(sizeof(no));
    if (aux == NULL) return;
    
    aux->valor = valor;
    aux->prox = NULL;
    
    if(f->ultimo != NULL){
        f->ultimo->prox = aux;
    }
    else{
        f->primeiro = aux;
    }
    f->ultimo = aux;
    f->qtdElementos++;
}

// Desenfileirar
int desenfileirar(Fila* f) {
    if(f->primeiro != NULL){
        no* aux = f->primeiro;
        int valor = aux->valor;
        
        f->primeiro = f->primeiro->prox;
        free(aux);
        f->qtdElementos--;
        
        // Se a fila esvaziou, atualiza o último ponteiro também
        if(f->primeiro == NULL) {
            f->ultimo = NULL;
        }
        
        return valor;
    }
    else{
        printf("Fila Vazia!\n");
        return -1; // Retorno de erro
    }
}
// ---------- ESTRUTURA DE PILHA ----------
// Estrutura "Pilha": 
typedef struct Pilha{
    no* topo;
}Pilha;

// Inicializa pilha
Pilha* criaPilha() {
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    if (p != NULL) {
        p->topo = NULL;
    }
    return p;
}

// Verifica se pilha está vazia
int pilhaVazia(Pilha* p) {
    if(p->topo == NULL){
        return 1;
    }
    return 0;
}

// Empilhar
void empilhar(Pilha* p, int valor) {
    no* novoNo = (no*)malloc(sizeof(no));
    if (novoNo != NULL) {
        novoNo->valor = valor;
        novoNo->prox = p->topo;
        p->topo = novoNo;
    }   
}

// Desempilhar
int desempilhar(Pilha* p) {
    if(p->topo != NULL){
        no* aux = p->topo;
        int valor = aux->valor;
        
        p->topo = p->topo->prox;
        free(aux);
        return valor;
    }
    else{
        printf("Pilha Vazia\n");
        return -1; // Retorno de erro
    }
}

// ---------- ALGORITMO ----------
// Processamento da fila F:
void processaFila(Fila* F, Fila *F1, Pilha *P1) {
    while (!filaVazia(F)) {
        int valor = desenfileirar(F);
        
        if (valor % 2 == 0) {
            empilhar(P1, valor);
        } 
        else {
            enfileirar(F1, valor);
        }
    }
}
int main(){
    Fila* F = criaFila();
    Fila* F1 = criaFila();
    Pilha* P1 = criaPilha();
    
    enfileirar(F, 1);
    enfileirar(F, 2);
    enfileirar(F, 3);
    enfileirar(F, 4);
    enfileirar(F, 5);
    enfileirar(F, 6);
    enfileirar(F, 7);
    enfileirar(F, 8);
    enfileirar(F, 9);
    enfileirar(F, 10);

    processaFila(F, F1, P1);

    return 0;
}