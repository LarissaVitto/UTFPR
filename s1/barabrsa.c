#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	int i, j, subtotal = 0;  
    int itens_disponiveis = 10;
	int total_prod = 10, quantidade, vercod, max_car = 10;
	float total, total_final = 0; 
	char escolha;
	int index_carrinho = 0;
	int codigos[] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};
	float precos[] = {5.5, 7.2, 4.0, 3.8, 1.5, 1.2, 2.7, 4.7, 6.9, 12.2};
	float carrinho[10][3] = {0};
	char lista[][20] = {"Arroz", "Feijao", "Macarrao", "Farinha", "Cenoura", "Alface", "Laranja", "Banana", "Leite", "Ovos"};
	
	printf("------ Mercado UTFPR -------\n");
	printf("----------------------------\n");
	printf("------ Lista de itens ------\n");
	printf("----------------------------\n");
	printf("Codigo | Produto   | Preco\n");
	for(i = 0; i < total_prod; i++){
		printf("%-5d  | %-8s  | %-6.2f\n", codigos[i], lista[i], precos[i]);
	}
	printf("\n");
	printf("Voce deseja adicionar um item ao carrinho?\n");
	printf("Digite S (sim) ou N (nao)\n");
	scanf(" %c", &escolha);
	
	while(escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n' ){
		printf("Algo esta errado\n");
		printf("Digite sua resposta novamente:\n");
		scanf(" %c", &escolha);
	}
	
	if(escolha == 'S' || escolha == 's'){
		while(max_car > 0){
			printf("Digite o codigo do produto:\n"); 
			scanf("%d", &vercod);
			
			int codigo_valido = 0;
	        for(i = 0; i < total_prod; i++) {
	            if(vercod == codigos[i]) {
	                codigo_valido = 1;
	                break;
	            }
	        }
	        
	        if(codigo_valido != 1) {
	            printf("Codigo invalido. Por favor, digite novamente o codigo do produto!\n");
	            continue;
	        }
        
			carrinho[index_carrinho][0] = vercod; 
			printf("Digite a quantidade:\n");
			scanf("%d", &quantidade);
			
			while(quantidade > itens_disponiveis || quantidade < 1){
				printf("Essa quantidade e invalida. Por favor, digite novamente:\n");
				scanf("%d", &quantidade);
			}
			
			float preco = 0;
	        for(i = 0; i < total_prod; i++) {
	            if(vercod == codigos[i]) {
	                preco = precos[i];
	                break;
	            }
	        }
			
			carrinho[index_carrinho][1] = quantidade; 
			total = quantidade * preco;
			carrinho[index_carrinho][2] = total;
			index_carrinho++;  
			subtotal += subtotal * preco; 
			printf("Valor adicionado ao carrinho: %.2f\n\n", total);
			
			max_car = max_car - quantidade;
			if(max_car != 0){
				itens_disponiveis = itens_disponiveis - quantidade;
					printf("Voce deseja adicionar mais um produto ao carrinho?\n");
					printf("Digite S (sim) ou N (nao)\n");
					scanf(" %c", &escolha);
			}
			
			while(escolha != 'S' && escolha != 's' && escolha != 'N' && escolha != 'n' ){
				printf("Voce digitou algo errado\nDigite S (sim) ou S (nao) novamente:\n");
				scanf(" %c", &escolha);
			}
			if(escolha == 'N' || escolha == 'n'){
				break;
			}
		}
	}else if(escolha == 'N' || escolha == 'n'){
		system("cls");
		printf("Nenhum item foi adicionado ao carrinho. Obrigado pela visita!");
		return 0;
	}
	
	//system("cls");
	
	printf("Compra finalizada!\n");
	printf("------------------------ Nota fiscal ----------------------\n");
	printf("-----------------------------------------------------------\n");
	printf("| Codigo | Produto  | Preco unit. | Quantidade | Subtotal |\n");
		for(i = 0; i < index_carrinho; i++){
			int cod = carrinho[i][0];
			int qtd = carrinho[i][1];
			float preco_un = 0;
			char nome_prod[20];
			for(j = 0; j < total_prod; j++){
			    if(cod == codigos[j]){
			        strcpy(nome_prod, lista[j]);
			        preco_un = precos[j];
			        break;
			    }
			}
		float subtotal = qtd * preco_un;
		total_final += subtotal;
		printf("| %-6d | %-8s | %-11.2f | %-10d | %-8.2f |\n", cod, nome_prod, preco_un, qtd, subtotal);
		}
	printf("-----------------------------------------------------------\n");
	printf("Total da compra:.................................%.2f", total_final);	
	
}
