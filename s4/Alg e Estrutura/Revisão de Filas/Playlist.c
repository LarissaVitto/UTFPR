typedef struct Musica {
    char titulo[100];
    char cantor[100];
} Musica;

typedef struct No {
    Musica msc;
    struct No *ant;
    struct No *prox;
} No;

typedef struct Playlist {
    No *inicio;
    No *fim;
    No *atual;
    int qtd;
} Playlist;

Playlist *criarPlaylist() {
    Playlist *p = (Playlist *) malloc(sizeof(Playlist));
    if (p != NULL) {
        p->inicio = NULL;
        p->fim = NULL;
        p->atual = NULL;
        p->qtd = 0;
    }
    return p;
}

void adicionarMusica(Playlist *p, Musica *m) {
    No *novo = (No *) malloc(sizeof(No));
    if (p == NULL) return;
    if (novo == NULL) return;
    novo->msc = *m;
    novo->prox = NULL;
    novo->ant = p->fim;

    if (p->inicio == NULL) {
        p->inicio = novo;
        p->fim = novo;
        p->atual = novo;
    } else {
        p->fim->prox = novo;
        p->fim = novo;
    }
    p->qtd++;
}

void musicaAtual(Playlist *p) {
    if (p != NULL && p->atual != NULL) {
        printf("%s - %s\n", p->atual->msc.cantor, p->atual->msc.titulo);
    } else {
        return;
    }
}

void avancar(Playlist *p) {
    if (p != NULL && p->atual != NULL && p->atual->prox != NULL) {
        p->atual = p->atual->prox;
    } else {
        return;
    }
}

void retroceder(Playlist *p) {
    if (p != NULL && p->atual != NULL && p->atual->ant != NULL) {
        p->atual = p->atual->ant;
    } else {
        return;
    }
}