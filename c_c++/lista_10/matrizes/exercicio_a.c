#include <stdio.h>


// 1 - Imprimir todos os elementos
int printAllCells(int mtx[3][2]) {
    printf("Todos os elementos da matriz:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", mtx[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// 2 - Somar os elementos de cada linha e mostrar o resultado
int printLineAdd(int mtx[3][2]) {
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        for (int j = 0; j < 2; j++) {
            sum += mtx[i][j];
        }
        printf("Soma dos elementos da linha %d: %d\n", i, sum);
    }
    return 0;
}

// 3 - Somar os elementos de cada coluna e mostrar o resultado
int printColAdd(int mtx[3][2]) {
    for (int j = 0; j < 2; j++) {
        int sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += mtx[i][j];
        }
        printf("Soma dos elementos da coluna %d: %d\n", j, sum);
    }
    return 0;
}

// 4 - Imprimir os elementos da diagonal principal
int printMainDiagonal(int mtx[3][2]) {
    printf("Elementos da diagonal principal:\n");
    for (int i = 0; i < 2 && i < 3; i++) {
        printf("%d ", mtx[i][i]);
    }
    printf("\n");
    return 0;
}

// 5 - Imprimir todos os elementos, exceto os da diagonal principal
int printEveryNotMainDiagonal(int mtx[3][2]) {
    printf("Elementos fora da diagonal principal:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            if (i != j) {
                printf("%d ", mtx[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}

// 6 - Imprimir os elementos, tal que a linha é par e a coluna é ímpar
int printEvenAndOdd(int mtx[3][2]) {
    printf("Elementos em linha par e coluna ímpar:\n");
    for (int i = 0; i < 3; i += 2) {
        for (int j = 1; j < 2; j += 2) {
            printf("%d ", mtx[i][j]);
        }
    }
    printf("\n");
    return 0;
}

// 7 - Imprimir os elementos da coluna 0
int printZeroCol(int mtx[3][2]) {
    printf("Elementos da coluna 0:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", mtx[i][0]);
    }
    printf("\n");
    return 0;
}

// 8 - Imprimir apenas os elementos das colunas múltiplos de 2
int printColWithTwoMultiples(int mtx[3][2]) {
    printf("Elementos das colunas múltiplos de 2:\n");
    for (int j = 0; j < 2; j++) {
        if (j % 2 == 0) {
            for (int i = 0; i < 3; i++) {
                printf("%d ", mtx[i][j]);
            }
        }
    }
    printf("\n");
    return 0;
}

// funcão principal
int main() {
  int mtx[3][2];

  printf("Entre com os algarismos da sua matriz 3x2\n");
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j <2; j++) {
      scanf("%d", &mtx[i][j]);
    }
  }

  int n = 0;

  printf("Escolha qual a sua operação\n");
  printf("1 - Imprimir todos os elementos\n");
  printf("2 - Somar os elementos de cada linha e mostrar o resultado\n");
  printf("3 - Somar os elementos de cada coluna e mostrar o resultado\n");
  printf("4 - Imprimir os elementos da diagonal principal\n");
  printf("5 - Imprimir todos os elementos, exceto os da diagonal principal\n");
  printf("6 - Imprimir os elementos, tal que a linha é par e a coluna é ímpar\n");
  printf("7 - Imprimir os elementos da coluna 0\n");
  printf("8 - Imprimir apenas os elementos das colunas multiplos de 2\n");

  scanf("%d", &n);

  switch (n) {
    case 1:
      printAllCells(mtx);
      break;
    case 2:
      printLineAdd(mtx);
      break;
    case 3:
      printColAdd(mtx);
      break;
    case 4:
      printMainDiagonal(mtx);
      break;
    case 5:
      printEveryNotMainDiagonal(mtx);
      break;
    case 6:
      printEvenAndOdd(mtx);
      break;
    case 7:
      printZeroCol(mtx);
      break;
    case 8:
      printColWithTwoMultiples(mtx);
      break;
    default:
      printf("Opção inválida!\n");
      break;
  }

  return 0;
}
