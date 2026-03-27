#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i, k, m = 0;     // contadores
    int carrinho[10][3]; // matriz do carrinho 10 linhas 3 colunas
    int num = 0;         // numero de itens q ele vai querer adicionar
    int codigo;          // variavel p verificar se o codigo é valido
    double subtotal[10], total = 0.0;
    int codigos_barras[5] = {101, 102, 103, 104, 105};                                // vetor dos codigos de barras
    char nomes_produtos[][20] = {"Arroz", "Feijao", "Macarrao", "Farinha", "Acucar"}; // string dos nomes
    float precos[5] = {5.5, 7.2, 4.0, 3.8, 2.5};                                      // vetor dos preços

    printf("=====================================\n");
    printf("Produtos Disponiveis:\n");
    printf("=====================================\n");

    for (i = 0; i < 5; i++)
    {
        printf("Codigo De Barras: %d \nNome do Produto:  %s \nPreco:            R$ %.2f \n", codigos_barras[i], nomes_produtos[i], precos[i]);
        printf("-------------------------------------\n");
    }

    do
    {
        printf("Quantos itens quer adicionar ao seu carrinho?\n");
        scanf("%d", &num);
        if (num <= 0 || num > 10)
        {
            printf("Valor invalido, digite novamente\n");
        }
    } while (num <= 0 || num > 10);
    printf("-------------------------------------\n");

    for (k = 0; k < num; k++)
    {
        printf("Digite o codigo de barras do Produto:\n");
        scanf("%d", &codigo);

        int valido = 0;
        m = 0;
        do
        {
            if (codigos_barras[m] == codigo)
            {
                valido = 1;
                break;
            }
            m++;
        } while (m < 5);
        if (valido)
        {
            carrinho[k][0] = codigo;
            int quantidade;

            do
            {
                printf("-------------------------------------\n");
                printf("Qual a quantidade do produto?\n");
                scanf("%d", &quantidade);
                if (quantidade <= 0)
                {
                    printf("Quantidade invalida! Tente novamente.\n");
                }
            } while (quantidade <= 0);

            carrinho[k][1] = quantidade;
            subtotal[k] = precos[m] * quantidade;
            carrinho[k][2] = subtotal[k];
            total += subtotal[k];

            printf("Produto adicionado com sucesso!\n");
            printf("-------------------------------------\n");
        }
        else
        {
            printf("Codigo invalido! Tente novamente.\n");
            k--;
        }
    }
    printf("\n============ NOTA FISCAL ============\n");

    for (i = 0; i < num; i++)
    {
        int cod = carrinho[i][0];
        int qtd = carrinho[i][1];
        char nome[20];
        float precouni = 0;

        for (m = 0; m < 5; m++)
        {
            if (codigos_barras[m] == cod)
            {
                strcpy(nome, nomes_produtos[m]);
                precouni = precos[m];
                break;
            }
        }
        printf("Produto: %s\n", nome);
        printf("Quantidade: %d\n", qtd);
        printf("Preco unitario: R$ %.2f\n", precouni);
        printf("Subtotal: R$ %.2lf\n", subtotal[i]);
        printf("-------------------------------------\n");
    }
    printf("TOTAL: R$ %.2lf\n", total);
    return 0;
}