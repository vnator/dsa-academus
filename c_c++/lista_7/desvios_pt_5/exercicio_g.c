#include <stdio.h>

int main(void) {
    // Dados do produto
    float preco_item = 5.00;
    int quantidade_itens;

    // Dados do cliente
    char* nome_cliente;
    char* cidade;
    char* bairro;
    char* rua;
    char* cep;
    char* nome_loja;
    char* cnpj;
    int numero_casa;

    // Dados da região
    int codigo_regiao;
    float percentual_frete;

    // Entrada de dados
    printf("Digite o nome do cliente: ");
    scanf("%s", nome_cliente);
    printf("Digite o nome da loja: ");
    scanf("%s", nome_loja);
    printf("\nDigite o CNPJ da loja: ");
    scanf("%s", cnpj);
    printf("\nDigite a cidade: ");
    scanf("%s", cidade);
    printf("\nDigite o bairro: ");
    scanf("%s", bairro);
    printf("\nDigite a rua: ");
    scanf("%s", rua);
    printf("\nDigite o CEP: ");
    scanf("%s", cep);
    printf("\nDigite o número da casa: ");
    scanf("%d", &numero_casa);
    printf("\nDigite a quantidade de itens (até 100): ");
    scanf("%d", &quantidade_itens);
    printf("\nDigite o código da região (1-Norte, 2-Nordeste, 3-Centro-Oeste, 4-Sudeste, 5-Sul): ");
    scanf("%d", &codigo_regiao);

    float total_sem_frete = preco_item * quantidade_itens;
    switch (codigo_regiao) {
        case 1:
            percentual_frete = 0.10;
            break;
        case 2:
            percentual_frete = 0.08;
            break;
        case 3:
            percentual_frete = 0.12;
            break;
        case 4:
            percentual_frete = 0.15;
            break;
        case 5:
            percentual_frete = 0.11;
            break;
        default:
            printf("\nCódigo de região inválido. Encerrando o programa.");
            return 1;
    }

    float valor_frete = total_sem_frete * percentual_frete;
    float total_com_frete = total_sem_frete + valor_frete;


    printf("\nDados do cliente");
    printf("\nNome: %s", nome_cliente);
    printf("\nCidade: %s", cidade);
    printf("\nBairro: %s", bairro);
    printf("\nRua: %s", rua);
    printf("\nCEP: %s", cep);
    printf("\nNúmero da casa: %d", numero_casa);

    printf("\nRegião de entrega: ");
    switch (codigo_regiao) {
        case 1:
            printf("\nNorte");
            break;
        case 2:
            printf("\nNordeste");
            break;
        case 3:
            printf("\nCentro-Oeste");
            break;
        case 4:
            printf("\nSudeste");
            break;
        case 5:
            printf("\nSul");
            break;
        default:
            printf("\nCódigo de região inválido. Encerrando o programa.");
            return 1;
    }

    printf("\nTotal de itens: %d", quantidade_itens);
    printf("\nTotal a pagar (sem frete): R$ %.2f, com frete: R$ %.2f", total_sem_frete, total_com_frete);
    
    printf("\nNome da empresa: %s", nome_loja);
    printf("CNPJ: %s", cnpj);

    return 0;
}