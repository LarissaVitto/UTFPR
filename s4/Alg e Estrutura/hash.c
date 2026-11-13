#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO_TABELA 35

typedef struct Aluno {
    int ra;
    char nome[50];
    struct Aluno *prox;
} Aluno;

typedef struct {
    Aluno* registros[TAMANHO_TABELA];
} TabelaHash;

int funcaoHash(int ra) {
    return abs(ra) % TAMANHO_TABELA;
}

void inicializarTabela(TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        tabela->registros[i] = NULL;
    }
}

Aluno* criarAluno(int ra, const char* nome) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    if (novoAluno == NULL) {
        perror("Erro ao alocar memoria");
        exit(EXIT_FAILURE);
    }
    novoAluno->ra = ra;
    strncpy(novoAluno->nome, nome, sizeof(novoAluno->nome) - 1);
    novoAluno->nome[sizeof(novoAluno->nome) - 1] = '\0';
    novoAluno->prox = NULL;
    return novoAluno;
}

void inserirAluno(TabelaHash* tabela, Aluno* aluno) {
    int indice = funcaoHash(aluno->ra);
    Aluno* aux = tabela->registros[indice];

    if (aux == NULL) {
        tabela->registros[indice] = aluno;
    } else {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = aluno;
    }
}

void imprimirTabela(TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Aluno* aux = tabela->registros[i];
        if (aux != NULL) {
            printf("Indice %d: ", i);
            while (aux != NULL) {
                printf("[RA: %d, Nome: %s] -> ", aux->ra, aux->nome);
                aux = aux->prox;
            }
            printf("NULL\n");
        }
    }
}

void liberarTabela(TabelaHash* tabela) {
    for (int i = 0; i < TAMANHO_TABELA; i++) {
        Aluno* aux = tabela->registros[i];
        while (aux != NULL) {
            Aluno* temp = aux;
            aux = aux->prox;
            free(temp);
        }
        tabela->registros[i] = NULL;
    }
}

int main() {
    TabelaHash tabela;
    inicializarTabela(&tabela);

    inserirAluno(&tabela, criarAluno(10, "Ana"));
    inserirAluno(&tabela, criarAluno(45, "Bruno"));
    inserirAluno(&tabela, criarAluno(22, "Carla"));

    imprimirTabela(&tabela);
    liberarTabela(&tabela);

    return 0;
}