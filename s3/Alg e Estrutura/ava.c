/*1. Há exatamente 2 (dois) erros no código que impedem o seu funcionamento adequado. Para
cada problema encontrado, indique:
(a) O número da(s) linha(s) onde o problema ocorre, ou, número da linha acima de onde
você adicionaria o código correto.
Ocorre nas linhas 11 e 18

(b) A razão/motivo pela qual o trecho está incorreto.
linha 11 estava faltando a alocação de memória
linha 18 estava faltando verificar se era o primeiro nó (raiz)

(c) O trecho de código corrigido correspondente àquela linha.
linha 11 No* novoNo = (No*)malloc(sizeof(No));
linha 18 if(raiz == NULL){
	return criaNoArvore(valor);
	}else*/

# include < stdio .h >
# include < stdlib .h >

typedef struct No {
int chave ;
struct No * esquerda ;
struct No * direita ;
} No ;

struct No * criarNo ( int chave ) {
	No* novoNo = (No*)malloc(sizeof(No)); // estava faltando a alocação de memória
novoNo - > chave = chave ;
novoNo - > esquerda = NULL ;
novoNo - > direita = NULL ;
return novoNo ;
}

struct No * inserir ( struct No * raiz , int chave ) {
	if(raiz == NULL){
	return criaNoArvore(valor); //estava faltando verificar se era o primeiro nó (raiz)
	}else
if ( chave < raiz - > chave ) {
raiz - > esquerda = inserir ( raiz - > esquerda , chave ) ;
} else if ( chave > raiz - > chave ) {
raiz - > direita = inserir ( raiz - > direita , chave ) ;
}
return raiz ;
}

/*2. Um jogo de RPG utiliza uma árvore binária para representar os caminhos possíveis de cada
decisão do jogador. Cada fase do jogo deve armazenar: (1) Código da decisão a ser tomada
(inteiro); (2) Texto de descrição da situação; (3) Até dois caminhos possíveis, cada uma
representando uma nova decisão que o jogador pode tomar.
A raiz da árvore representa o início da aventura. Cada subárvore representa um caminho
diferente que pode ser seguido pelo jogador de acordo com suas escolhas durante o jogo.
Implemente o que é solicitado abaixo.

(a) Implemente a definição da estrutura para representar as fases da aventura.*/
typedef struct fase{
int codigo;
char frase[100]; //texto de descrição
struct fase *esquerda; //decisoes para esquerda ou direita
struct fase *direita;
}fase;


/*(b) Escreva uma função para calcular o número total máximo de fases que um jogador pode
percorrer durante uma aventura.
*/
int maxFases = -1;
int totalFases(fase* raiz){
	if(fase == NULL){
	return -1;
	}else{
		int maxEsquerda = maxArvore(fase->esquerda);
		int maxDireita = maxArvore(fase->direita);
		if(maxEsquerda > maxDireita){
			return maxEsquerda + 1;
			}else{
				return maxDireita + 1;
			}
		}
	}
return maxFases;
}
