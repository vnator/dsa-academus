// E. Faça uma solução para calcular o total a pagar sobre determinada compra,
// bem como o possível frete para a entrega do produto a partir da região do
// Brasil. Considere que todos os itens apresentem o mesmo preço (5,00), e o
// usuário pode comprar até 100 itens
// Código de regiões:
// 1 – Norte: 10% da compra, 2 – Nordeste: 8% da compra, 3 – Centro-Oeste: 12% da
// compra, 4 – Sudeste: 15% da compra, 5 – Sul: 11% da compra
// Apresentar o total a pagar, sem o frete e com o frete, e mostrar a região de
// entrega
#include <stdio.h>

int main () {
  float quantidade, frete, total, total_final;
  int opcao;
  char *regiao;

  printf("Quantos itens foram comprados: ");
  printf("%d", &quantidade);

  printf("\nqual é a sua região: ");
  printf("\n 1 - Norte");
  printf("\n 2 - Norteste");
  printf("\n 3 - Centro-Oeste");
  printf("\n 4 - Sudeste");
  printf("\n 5 - Sul");
  scanf("%d", &opcao);

  switch(opcao) {
    case 1:
      frete = 0.10;
      regiao = "Norte";
      break;
    case 2:
      frete = 0.08;
      regiao = "Nordeste";
      break;
    case 3:
      frete = 0.12;
      regiao = "Centro-Oeste";
      break;
    case 4:
      frete = 0.15;
      regiao = "Sudeste";
      break;
    default:
      frete = 0.11;
      regiao = "Sul";
  }

  total=quantidade*5;
  total_final=total+(total*frete);

  printf("Total: %.2f, Total com para a região de %s: %.2f", total, regiao, total_final);

  return 0;
}
