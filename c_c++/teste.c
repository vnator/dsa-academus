#include <stdio.h>

// funcional
int soma(int a, int b) { return a + b; }

int main() {
  // empilha d
  int d = 5;

  void alteraD(int e, int a) {
    d = e + a;
    int f = 3;
  }

  printf("Hello world");

  // empinha c, empinha a, empilha b
  int c = soma(2, 4);
  // desempilha a, desempilha b

  // c, a, f
  alteraD(c, 32);

  return 0;
}

// STACK [0 1 2 3 4 5 6 7 8 9 10]
// d -> [0]
// c -> [1]
// | -> a -> [2], b -> [3]
// a -> [2] -> x
// b -> [3] -> x
// -> e -> [2], a -> [3]
/// e -> [2] -> x
// a -> [3] -> x
// c -> [1]
// d -> [0]
