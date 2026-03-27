#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// corzinhas uau
#define TEXTO_VERMELHO     "\x1b[31m"
#define TEXTO_VERDE   "\x1b[32m" 
#define TEXTO_AZUL   "\x1b[34m" 
#define TEXTO_AMARELO  "\x1b[33m" 
#define TEXTO_ROXO "\x1b[35m" 
#define TEXTO_CINZA "\x1b[90m" 
#define RESETAR_COR   "\x1b[0m" // Resetar para a cor padrão do terminal
// corzinhas uau

const char* carta_jogo[22] = {
    "gato","gato",
    "cachorro","cachorro",
    "peixe","peixe",
    "urso","urso",
    "rato","rato",
    "leao","leao",
    "tigre","tigre",
    "macaco","macaco",
    "cobra","cobra",
    "elefante","elefante",
    "girafa","girafa"
    };

int acertos = 0; // inicializa os acertos em 0
int erros = 0;   // inicializa os erros em 0

//  variaveis globais para salvar/carregar jogo
int existe_savefile_flag = 0; // cache simples (pode ser atualizado por existe_save())
int loaded_save = 0; // indica que o menu carregou um save para iniciar o jogo
int current_tam_baralho = 0;
int current_lin = 0;
int current_col = 0;
char ***current_tabuleiro = NULL; // ponteiro atual do tabuleiro (usado para salvar ao sair)
int **current_visivel = NULL;     // ponteiro atual da matriz visivel (usado para salvar ao sair)
/* ---------------------------------------------------------------------------------- */

void alocar_cartas_baralho(char**baralho, int num_cartas);
void embaralhar_baralho(char **baralho_jogo, int tam_baralho);
char *** criar_tab(int tam, char **baralho, int *lin, int *col);
int ** criar_matriz_visivel(int lin, int col);
void mostrar_tabuleiro(char ***tabuleiro, int **visivel, int lin, int col);
int escolher_posicao(int lin, int col, int primeira_esc);
void lin_col(int pos, int colunas, int *l, int *c);
void limpar_tela();
void tabuleiro_completo(char ***tabuleiro, int lin, int col);
void menu();
void sair();
void jogar_novamente();
 
// Verifica se existe o arquivo de save, se existe retorna 1 senão 0
int existe_save() {
    FILE *f = fopen("save.bin", "rb");
    if (f == NULL) return 0;
    fclose(f);
    return 1;
}

void salvar_jogo(int tam_baralho, int lin, int col, char ***tabuleiro, int **visivel) { // salva o jogo todo em sabe.bin
    FILE *f = fopen("save.bin", "wb");
    if (!f) {
        printf("Erro ao salvar jogo!\n");
        return;
    }

    fwrite(&tam_baralho, sizeof(int), 1, f);
    fwrite(&lin, sizeof(int), 1, f);
    fwrite(&col, sizeof(int), 1, f);
    fwrite(&acertos, sizeof(int), 1, f);
    fwrite(&erros, sizeof(int), 1, f);

    // salvar cada string com seu comprimento com o \0
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j < col; j++) {
            int len = strlen(tabuleiro[i][j]) + 1;
            fwrite(&len, sizeof(int), 1, f);
            fwrite(tabuleiro[i][j], sizeof(char), len, f);
        }
    }

    // salvar matriz visivel (lin x col)
    for (int i = 0; i < lin; i++) {
        fwrite(visivel[i], sizeof(int), col, f);
    }

    fclose(f);
    existe_savefile_flag = 1;
}
char ***carregar_jogo(int *tam_baralho, int *lin, int *col, int ***visivel) { // carrega o jogo anterior
    FILE *f = fopen("save.bin", "rb");
    if (!f) {
        return NULL;
    }

    fread(tam_baralho, sizeof(int), 1, f);
    fread(lin, sizeof(int), 1, f);
    fread(col, sizeof(int), 1, f);
    fread(&acertos, sizeof(int), 1, f);
    fread(&erros, sizeof(int), 1, f);

    char ***tab = malloc((*lin) * sizeof(char**));
    for (int i = 0; i < *lin; i++) {
        tab[i] = malloc((*col) * sizeof(char*));
    }

    for (int i = 0; i < *lin; i++) {
        for (int j = 0; j < *col; j++) {
            int len;
            fread(&len, sizeof(int), 1, f);
            tab[i][j] = malloc(len);
            fread(tab[i][j], sizeof(char), len, f);
        }
    }

    *visivel = malloc((*lin) * sizeof(int*));
    for (int i = 0; i < *lin; i++) {
        (*visivel)[i] = malloc((*col) * sizeof(int));
        fread((*visivel)[i], sizeof(int), (*col), f);
    }

    fclose(f);
    existe_savefile_flag = 1;
    return tab;
}


int main(){
    int tam_baralho = 0;
    char **baralho_jogo = NULL;

    // reseta as variaveis globais do save
    current_tabuleiro = NULL;
    current_visivel = NULL;
    current_tam_baralho = 0;
    current_lin = 0;
    current_col = 0;
    loaded_save = 0;

    menu(); // abre o menu do jogo

    if (loaded_save) { // se existir um save carregado usa ele, como se fosse a main mas está tudo aqui usando o save antigo
        tam_baralho = current_tam_baralho;
        int lin = current_lin;
        int col = current_col;
        char ***tabuleiro = current_tabuleiro;
        int **visivel = current_visivel;
        int total_pares = tam_baralho/2;

        // define as variaveis q o jogo espera
        int lin_local = lin;
        int col_local = col;
        time_t tempo_inicial = time(NULL); // Pega o tempo atual em segundos
        time_t tempo_limite = tempo_inicial + 0; // Soma os 30 segundos pra sumir o tabuleiro
        printf(TEXTO_AMARELO "Memorize o tabuleiro! Limpando em 30 segundos..." RESETAR_COR);
        tabuleiro_completo(tabuleiro, lin_local, col_local); // Mostra o tabuleiro inteiro por 30 segundos
        
        while (time(NULL) < tempo_limite) { /* nada */ }
        limpar_tela();

        tabuleiro_completo(tabuleiro, lin_local, col_local);

        while(acertos<total_pares){
            mostrar_tabuleiro(tabuleiro, visivel, lin_local, col_local);

            int p1, l1, c1;
            do {
                printf("\nEscolha a primeira carta:\n");
                p1 = escolher_posicao(lin_local, col_local, -1); // -1 pra indicar que nao tem nada para comparar (primeira escolha)
                printf(TEXTO_VERDE "Pontuacao: %d\n" RESETAR_COR, acertos);
                lin_col(p1, col_local, &l1, &c1); // Converte a posição para linha e coluna

                if (visivel[l1][c1] == 1) {
                    printf("Essa carta ja esta virada! Escolha outra.\n");
                }
            } while (visivel[l1][c1] == 1);

            visivel[l1][c1] = 1;
            printf("=================================");
            mostrar_tabuleiro(tabuleiro, visivel, lin_local, col_local);

            int p2, l2, c2;
            do {
                printf("\nEscolha a segunda carta:\n");
                p2 = escolher_posicao(lin_local, col_local, p1);
                lin_col(p2, col_local, &l2, &c2);

                if (visivel[l2][c2] == 1) {
                    printf("Essa carta ja esta virada! Escolha outra, Teruo.\n");
                }
            } while (visivel[l2][c2] == 1);

            visivel[l2][c2] = 1;
            limpar_tela();
            mostrar_tabuleiro(tabuleiro, visivel, lin_local, col_local);
            
            int acertou = 0;
            
            if(strcmp(tabuleiro[l1][c1], tabuleiro[l2][c2]) == 0){
                printf(TEXTO_VERDE"\nPar encontrado!\n" RESETAR_COR);
                acertos++; 
                acertou = 1;
                printf(TEXTO_VERDE "Pontuacao: %d\n" RESETAR_COR, acertos);
            }else{
                printf(TEXTO_VERMELHO "\nNao e par!\n" RESETAR_COR);
                erros++; 
            }

            printf(RESETAR_COR"\nPressione ENTER para continuar");
            getchar();

            if(!acertou){
                visivel[l1][c1] = 0;
                visivel[l2][c2] = 0;
            }
            limpar_tela();
        }

        printf("\n ======================\n");
        printf(" " TEXTO_AZUL "Voce finalizou o jogo, parabens!" RESETAR_COR "\n");
        printf(" Pontuacao final: %d\n", acertos);
        printf(" Erros: %d\n", erros);
        printf(" ======================\n");
        // salvar resultado final no save
        salvar_jogo(tam_baralho, lin_local, col_local, tabuleiro, visivel);
        jogar_novamente();

        //liberando as memórias do save
        for (int i = 0; i < lin_local; i++) {
            for (int j = 0; j < col_local; j++) {
                free(tabuleiro[i][j]);
            }
            free(tabuleiro[i]);
            free(visivel[i]);
        }
        free(tabuleiro);
        free(visivel);

        return 0;
    }

    // main normal, sem ser com arquivo carregado

    do {
        printf("Escolha o tamanho do seu baralho:\n18 Cartas "TEXTO_CINZA"(9 duplas)"RESETAR_COR"\n20 Cartas "TEXTO_CINZA"(10 duplas)"RESETAR_COR"\n22 Cartas "TEXTO_CINZA"(11 duplas)"RESETAR_COR"\n"); // colocar as opções para o usuario ver
        printf(TEXTO_VERDE "Pontuacao: %d\n" RESETAR_COR, acertos);
        printf("Outras opcoes:\n");
        printf(TEXTO_AZUL "1" RESETAR_COR " - Voltar ao menu     ");
        printf(TEXTO_VERMELHO "2" RESETAR_COR " - Sair\n");
        int validar_leitura = scanf("%d", &tam_baralho);
        
        while (getchar() != '\n'); // serve para limpar o buffer se o usuario digitou alguma letra ou algo do tipo.

        if(validar_leitura != 1){ // verifica se recebeu um inteiro
            printf("Valor inserido invalido! Informe um valor valido\n");
            continue;
        }
        
        if(tam_baralho == 18 || tam_baralho == 20 || tam_baralho == 22){
            break; 
        }else if(tam_baralho == 2){
            sair();
        }else if( tam_baralho == 1){
            main();
        }
         else{
            limpar_tela();
            printf("Valor inserido invalido! Informe um valor valido\n");
        }
    }while(1);

    baralho_jogo = malloc(tam_baralho * sizeof(char*)); // Aloca o tamanho para o ponteiro de ponteiros
    alocar_cartas_baralho(baralho_jogo,tam_baralho); // Aloca as cartas para o baralho dependendo do tam escolhido pelo usuario
    embaralhar_baralho(baralho_jogo,tam_baralho); // Distribui as cartas de forma aleatória

    int lin, col;
    char ***tabuleiro = criar_tab(tam_baralho, baralho_jogo, &lin, &col);  // cria a matriz das cartas (o tabuleiro real)
    int **visivel = criar_matriz_visivel(lin, col);  // cria a matriz de visibilidade (0 = oculta, 1 = revelada)
    int total_pares = tam_baralho/2;

    // Atualiza os ponteiros globais que salvam o jogo quando usa sair
    current_tam_baralho = tam_baralho;
    current_lin = lin;
    current_col = col;
    current_tabuleiro = tabuleiro;
    current_visivel = visivel;

    time_t tempo_inicial = time(NULL); // Pega o tempo atual em segundos
    time_t tempo_limite = tempo_inicial + 30; // Soma os 30 segundos pra sumir o tabuleiro
    printf(TEXTO_AMARELO "Memorize o tabuleiro! Limpando em 30 segundos..." RESETAR_COR);
    tabuleiro_completo(tabuleiro, lin, col); // Mostra o tabuleiro inteiro por 30 segundos
    
    while (time(NULL) < tempo_limite) { // Loop que roda até os 30seg
    }
    limpar_tela();

    //tabuleiro_completo(tabuleiro, lin, col); // tem que tirar essa linha depois, é só pra testar apagar excluir deletar dps ----------------------------------------------------------------

    while(acertos<total_pares){
        mostrar_tabuleiro(tabuleiro, visivel, lin, col); //enquanto a qtde de acertos for menor do que o total de pares vai mostrar o tabuleiro

        int p1, l1, c1;
        do {
            printf("\nEscolha a primeira carta:\n");
            p1 = escolher_posicao(lin, col, -1); // -1 pra indicar que nao tem nada para comparar (primeira escolha)
            printf(TEXTO_VERDE "Pontuacao: %d\n" RESETAR_COR, acertos);
            lin_col(p1, col, &l1, &c1); // Converte a posição para linha e coluna

            if (visivel[l1][c1] == 1) {
                printf("Essa carta ja esta virada! Escolha outra.\n");
            }
        } while (visivel[l1][c1] == 1); // Repete se escolher carta já aberta

        visivel[l1][c1] = 1; // Revela a primeira carta

        printf("=================================");

        mostrar_tabuleiro(tabuleiro, visivel, lin, col); // Mostra o tabuleiro com a primeira carta virada

       int p2, l2, c2;
        do {
            printf("\nEscolha a segunda carta:\n");
            p2 = escolher_posicao(lin, col, p1); // compara p2 e p1 para evitar escolher a mesma posição
            lin_col(p2, col, &l2, &c2); // Converte a posição para linha e coluna

            if (visivel[l2][c2] == 1) {
                printf("Essa carta ja esta virada! Escolha outra, Teruo.\n");
            }
        } while (visivel[l2][c2] == 1); // Repete se escolher carta já aberta

        visivel[l2][c2] = 1; // Revela a segunda carta

        limpar_tela();
        mostrar_tabuleiro(tabuleiro, visivel, lin, col);
        
        int acertou = 0;
        
        if(strcmp(tabuleiro[l1][c1], tabuleiro[l2][c2]) == 0){ //verifica se é par comparando as strings
            printf(TEXTO_VERDE"\nPar encontrado!\n" RESETAR_COR);
            acertos++; 
            acertou = 1;
            printf(TEXTO_VERDE "Pontuacao: %d\n" RESETAR_COR, acertos);
        }else{
            printf(TEXTO_VERMELHO "\nNao e par!\n" RESETAR_COR);
            erros++; 
        }

        printf(RESETAR_COR"\nPressione ENTER para continuar");
        getchar();

        if(!acertou){ // Se errou o par oculta as cartas escolhidas
            visivel[l1][c1] = 0;
            visivel[l2][c2] = 0;
        }
        limpar_tela();
    }

    printf("\n ======================\n");
    printf(" " TEXTO_AZUL "Voce finalizou o jogo, parabens!" RESETAR_COR "\n");
    printf(" Pontuacao final: %d\n", acertos);
    printf(" Erros: %d\n", erros);
    printf(" ======================\n");
    /* salva o jogo final ao terminar */
    salvar_jogo(tam_baralho, lin, col, tabuleiro, visivel);
    jogar_novamente();

    // liberando o espaço da memória do baralho
    for(int i = 0;i < tam_baralho; i++){ 
        free(baralho_jogo[i]); // libera o espaco de cada carta
    } free(baralho_jogo); // libera o espaço do ponteiro de ponteiro em si

    // liberando o espaço da memória do tabuleiro e da matriz visível
    for(int i = 0; i < lin; i++){
        free(tabuleiro[i]); 
        free(visivel[i]); 
    }
    free (tabuleiro); 
    free (visivel);

    return 0;
}
void alocar_cartas_baralho(char**baralho, int num_cartas){
    for(int i = 0;i < num_cartas;i++){
            baralho[i] = malloc(strlen(carta_jogo[i]) + 1); // Aloca espaço para a string (+1 para o '\0')
            strcpy(baralho[i], carta_jogo[i]); // Copia o nome da carta
    }
}
void embaralhar_baralho(char **baralho_jogo, int tam_baralho){ //serve para embaralhar o baralho
    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    for(int i = tam_baralho - 1; i > 0; i--){ // algoritimo de Fisher–Yates
        int j = rand() % (i+1); // Escolhe uma posição aleatória entre 0 e i
        char *var_temp_carta = baralho_jogo[i]; // armazena temporariamente a carta na posicao i para ser realocada
        baralho_jogo[i] = baralho_jogo[j]; // Troca a carta da posição i com a carta da posição j
        baralho_jogo[j] = var_temp_carta; // valor mudado de lugar
    }
}
char *** criar_tab(int tam, char **baralho, int *lin, int *col){
    *lin = 2; // O tabuleiro tem sempre 2 linhas
    if (tam==18) *col=9; //baralho 18 cartas (2x9)
    else if(tam==20) *col=10; // 20 cartas (2x10)
    else *col=11; // 22 cartas (2x11)

    char ***tab=malloc((*lin) * sizeof(char**));
    for(int i = 0; i < *lin; i++){
        tab[i]=malloc((*col)* sizeof(char*));
    }
    
    int k=0;
    for(int i=0; i<*lin;i++){ // Preenche o tabuleiro com as cartas do baralho
        for(int j=0;j<*col;j++){
            tab[i][j]=baralho[k++];
        }
    }
    return tab;
}
int ** criar_matriz_visivel(int lin, int col){ // vis = 0 oculta e = 1 revela
    int **vis = malloc(lin*sizeof(int*));
    for(int i = 0; i < lin; i++){
        vis[i]= calloc(col, sizeof(int)); // aloca e inicia todos os valores com 0
    }
    return vis;
}
void mostrar_tabuleiro(char ***tabuleiro, int **visivel, int lin, int col){ //serve para mostrar o tabuleiro usado durante o jogo
    printf(TEXTO_AZUL"\nTABULEIRO:\n" RESETAR_COR);
    int pos=1; //
    for(int i=0;i<lin;i++){ 
        for(int j=0;j<col;j++){
             if (visivel[i][j])//carta a mostra (visível é 1)
                printf("[%s]", tabuleiro[i][j]); // Exibe o nome da carta
            else //carta virada pra baixo (visível é 0)
                printf("[%02d] ", pos); // Exibe o número da posição (ex: 01, 02)
            pos++;
            }
             printf("\n");
        }
    }
int escolher_posicao(int lin, int col, int primeira_esc){ // Solicita e valida a escolha de posição do usuário
    int pos, max = lin * col;
    while(1){
        printf("Escolha a posicao da carta(1 a %d): \n", max);
        printf(TEXTO_VERDE "Pontuacao: %d\n", acertos);
        printf(RESETAR_COR "Outras opcoes:\n");
        printf(TEXTO_AZUL "98" RESETAR_COR " - Voltar ao menu     ");
        printf(TEXTO_VERMELHO "99" RESETAR_COR " - Sair\n");
        int leitura = scanf("%d", &pos);

        while (getchar() != '\n'); 
        
        if(leitura != 1){ // caso a resposta não seja um número
            printf("Entrada invalida! Digite apenas numeros, Teruo.\n");
            continue;
        }
        if(pos == 99){
            /* Ao sair durante o jogo, salvar automaticamente (se houver um tabuleiro atual) */
            if (current_tabuleiro != NULL && current_visivel != NULL && current_tam_baralho>0) {
                salvar_jogo(current_tam_baralho, current_lin, current_col, current_tabuleiro, current_visivel);
            }
            sair(); 
        }else if(pos == 98){
            main();
        }
            
        if(pos < 1 || pos > max){ //caso a resposta não esteja entre o limite estabelecido
            printf("Posicao fora do intervalo! Tente novamente.\n");
            continue;
        }
            
        if(pos == primeira_esc){ //caso a resposta seja igual a primeira escolha
            printf("Voce ja escolheu essa carta!\n");
            continue;
        }
     return pos; // Retorna a posição válida
    }
}
void lin_col(int pos, int colunas, int *l, int *c){ // Funcao serve para converter a carta escolhida (em numero) na posicao correspondente dentro da matrizd
    *l = (pos - 1) / colunas; 
    *c = (pos - 1) % colunas; 
}
void limpar_tela(){ // Limpa a tela do terminal
    #ifdef _WIN32 
    system("cls");
    #else 
    system("clear");
    #endif 
}
void tabuleiro_completo(char ***tabuleiro, int lin, int col){ // função para mostrar o tabuleiro completo na tela
    printf(TEXTO_AZUL "\nTABULEIRO\n" RESETAR_COR);
    for(int i=0; i < lin; i++){
        for(int j=0; j < col; j++){
            printf("[%s]", tabuleiro[i][j]);
        }
        printf("\n");
    }
}
void menu(){ // menu inicial do jogo
    int opcao = 0;
    int tem_save = existe_save();
    existe_savefile_flag = tem_save;

    printf(TEXTO_ROXO"Jogo Da Memoria\n" RESETAR_COR);
    printf("Escolha uma opcao:\n");
    printf(TEXTO_AZUL "1" RESETAR_COR " - Jogar\n");
    if (tem_save) {
        printf(TEXTO_AMARELO "2" RESETAR_COR " - Carregar ultimo jogo salvo\n");
    }
    printf(TEXTO_VERMELHO "3" RESETAR_COR " - Sair\n");
    scanf("%d", &opcao);
    while (getchar() != '\n');

    switch (opcao) {
        case 1:
            break;
        case 2:
            if (tem_save) {
                // carregar jogo e ajustar variaveis globais para poder usar o save 
                int tam_b, lin, col;
                int **vis;
                char ***tab = carregar_jogo(&tam_b, &lin, &col, &vis);
                if (tab != NULL) {
                    loaded_save = 1;
                    current_tam_baralho = tam_b;
                    current_lin = lin;
                    current_col = col;
                    current_tabuleiro = tab;
                    current_visivel = vis;
                    return;
                } else {
                    printf("Erro ao carregar jogo.\n");
                    limpar_tela();
                }
            } else {
                printf("Nenhum save encontrado.\n");
                limpar_tela();
            }
            break;
        case 3:
            sair();
        default:
            printf(TEXTO_VERMELHO"Opção invalida!"RESETAR_COR" Por favor, escolha 1, 2 ou 3.\n");
            break;
    }
    limpar_tela();
}
void sair(){ //serve para fechar o programa
    limpar_tela();
    printf("Obrigada por jogar!\n");
    exit(0);
}
void jogar_novamente() { // aparece a opção para jogar novamente no final do jogo
    int opcao = 0;
    printf("\nDeseja jogar novamente?\n");
    printf(TEXTO_VERDE "1" RESETAR_COR " - Sim\n");
    printf(TEXTO_VERMELHO "2" RESETAR_COR " - Nao\n");
    scanf("%d", &opcao);
    while (getchar() != '\n'); 
    if (opcao == 1) {
        limpar_tela();
        acertos = 0;
        erros = 0;
        main(); //recomeça o jogo
    } else {
        //salva o jogo caso esteja em andamento
        if (current_tabuleiro != NULL && current_visivel != NULL && current_tam_baralho>0) {
            salvar_jogo(current_tam_baralho, current_lin, current_col, current_tabuleiro, current_visivel);
        }
        sair();
    }
}
