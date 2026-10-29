#define SEM_ARESTA '\0'

void teste_1() {
    Grafo g;
    inicializarGrafo(&g);

    inserirAresta(&g, 'A', 'B', 40); // PB -> DV direto leva 40ms
    inserirAresta(&g, 'A', 'C', 12); // PB -> FB leva 12ms
    inserirAresta(&g, 'C', 'B', 15); // FB -> DV leva 15ms

    // Rota Direta (A -> B): 40ms
    // Rota Alternativa (A -> C -> B): 12 + 15 = 27ms
    // Economia esperada: 40 - 27 = 13ms
    printf("Rota Direta: %dms | Rota Alternativa (-): %dms.", 
            verificarRotaDireta(&g, 'A', 'B'), 
            verificarRotaAlternativa(&g, 'A', 'C', 'B'));
}

int verificarRotaDireta{
    
}

int verificaRotaAlternativa{

}