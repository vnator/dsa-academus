// F. Faça uma solução para o usuário informar sua situação civil e, de acordo
// com esta, realizar as seguintes operações:
// *Solteiro (a): informar a idade
// *Casado: informar o sexo e o nome do cônjuge
// *Divorciado: informar a quantidade de filhos (0, caso não possua filho) e a
// idade do mais velho
// *Viúvo: informar a cidade onde vive e o salário atual
// Mostrar a opção informada e as informações fornecidas
#include <stdio.h>
#include <ctype.h>

int main() {
  int estado_civil, idade, filhos, idade_filho;
  char sexo;
  char *conjugue, *cidade;
  float salario;

  printf("Digite o código do estado civil");
  printf("\n 0 - Solteiro");
  printf("\n 1 - Casado");
  printf("\n 2 - Divorciado");
  printf("\n 3 - Viuvo");
  scanf("%d", &estado_civil);

  switch (estado_civil) {
    case 0:
      printf("\nQual a sua idade: ");
      scanf("%d", &idade);
      printf("\nÉ solteiro(a) e tem %d anos.", idade);
      break;
    case 1:
      printf("\nQual o seu sexo? m = masculino, f = feminino: ");
      scanf("%c", &sexo);

      printf("\nQual o nome do seu conjugue?");
      scanf("%s", conjugue);
  
      tolower(sexo) == 'm' 
        ? printf("\nHomem Casado com ")
        : printf("\nMulher Casada com ");

      printf("%s.", conjugue);
      break;
    case 2:
      printf("\nQuantos filhos? ");
      scanf("%d", &filhos);
    
      if (filhos > 0) {
        printf("\nQual a idade do filho mais velho? ");
        scanf("%d", &idade_filho);
      }

      printf("\nDivorciado(a) e com %d filhos", filhos);
      if (filhos > 0)
        printf("\nSendo o mais velho com %d anos de idade", idade);
      
    default:
      printf("\nVive em qual cidade? ");
      scanf("%s", cidade);

      printf("\nQual o seu salario? ");
      scanf("%f", &salario);

      printf("Viúvo e vivem em %s, com o salario de %.2f", cidade, salario);

      break;
  }


  return 0;
}
