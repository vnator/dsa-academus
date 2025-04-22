// . Faça uma solução para decidir se um código informado pelo usuário é
// masculino ou feminino. Use a estrutura if-else para uma solução e o operador
// ternário para a outra 

#include <stdio.h>

int mascOuFemComIf(void) {
  char sexo;
  
  printf("informe o sexo (m/f)");
  scanf("%c", &sexo);

  if (sexo == 'm') {
    printf("Masculino");
  } else {
    printf("Feminino");
  }

  return 0;
}

int mascOuFemComTernario(void) {
  char sexo;

  printf("informe o sexo (m/f)");
  scanf("%c", &sexo);

  sexo == 'm'
    ? printf("Masculino")
    : printf("Feminino");

  return 0;
}
