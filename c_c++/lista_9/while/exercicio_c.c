#include <stdio.h>

int main() {
  int pass;

  while(1) {
    scanf("%d", &pass);

    if (pass == 2002)
      break;
      
    printf("Senha Invalida\n");
  }


  printf("Acesso Permitido\n");
  return 0;
}
