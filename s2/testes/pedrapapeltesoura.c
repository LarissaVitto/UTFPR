#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int geraAleatorio();
int menu();
int escolha();
int main(){
	srand(time(NULL));
    int partida = 1, resposta = 0;
    do{
        partida = menu();
        resposta = escolha();
        int aleat = 0;
        aleat = geraAleatorio();
        
        if(aleat == 1 && resposta == 1){
            printf("O computador escolheu Pedra! Empatou!\n");
        }else if( aleat == 1 && resposta == 2){
            printf("O computador escolheu Pedra! Voce Ganhou!\n");
        }else if( aleat == 1 && resposta == 3){
            printf("O computador escolheu Pedra! Voce Perdeu!\n");
        }

        if(aleat == 2 && resposta == 2){
            printf("O computador escolheu Papel! Empatou!\n");
        }else if( aleat == 2 && resposta == 1){
            printf("O computador escolheu Papel! Voce Ganhou!\n");
        }else if( aleat == 2 && resposta == 3){
            printf("O computador escolheu Papel! Voce Perdeu!\n");
        }
// dava pra arruma esses if e tal com < e > mas to com preguiça
        if(aleat == 3 && resposta == 3){
            printf("O computador escolheu Tesoura! Empatou!\n");
        }else if( aleat == 3 && resposta == 1){
            printf("O computador escolheu Tesoura! Voce Ganhou!\n");
        }else if( aleat == 3 && resposta == 2){
            printf("O computador escolheu Tesoura! Voce Perdeu!\n");
        }      
    }while( partida == 1);  
    return 0;
}
int geraAleatorio(){
	int num_aleatorio = rand()%3 + 1;// vão ser 3 aleatórios, +1 pq começa em 0 e a gente quer do 1 ao 3
	return num_aleatorio;
}
int menu(){
    int partida;
    printf("===============MENU================\n");
    printf("Quer iniciar uma nova partida?\n");
    printf("Sim - 1\n");
    printf("Nao - 2\n");
    scanf("%d", &partida);
    return partida;
}
int escolha(){
    int resposta;
    printf("==============ESCOLHA==============\n");
    printf("Qual você escolhe?\n");
    printf("Pedra - 1\n"); 
    printf("Papel - 2\n"); 
    printf("Tesoura - 3\n"); 
    scanf("%d", &resposta);
    printf("===================================\n");
    return resposta;
}