typedef struct Grafo {
    int num_vertices;
    int** matriz;
} Grafo;

Grafo* criar_grafo(int n) {
    Grafo* g = (Grafo*)malloc(sizeof(Grafo));
    g->num_vertices = n;
    g->matriz = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        g->matriz[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) g->matriz[i][j] = 0;
    }
    return g;
}

void adicionar_aresta(Grafo* g, int origem, int destino) {
    g->matriz[origem][destino] = 1;
    g->matriz[destino][origem] = 1;
}

int obter_grau(Grafo* g, int vertice) {
    // Implemente a varredura da linha da matriz referente ao vertice
   if (vertice < 0 || vertice >= g->num_vertices) {
        return 0;
    }
    int grau = 0;
    for (int i = 0; i < g->num_vertices; i++) {
        if (g->matriz[vertice][i] == 1) {
            grau++;
        }
    }
    return grau;
}