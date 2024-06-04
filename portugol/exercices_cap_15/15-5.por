programa {
  // Escreva um algoritmo que leia um n�mero inteiro positivo, n > 1, e determine e escreva a
  // sua decomposi��o em fatores primos, exibindo a multiplicidade de cada fator. Por exemplo,
  // se a entrada for n = 18, ent�o a sa�da deve ser da forma
  // 2 com multiplicidade 1
  // 3 com multiplicidade 2
  // pois 2 � 3 � 3 = 18 e 2 e 3 s�o n�meros primos.
  funcao inicio() {
    inteiro n, multi = 0

    escreva("Escreva um n�mero inteiro: ")
    leia(n)

    enquanto (n < 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(n)
    }

    para(inteiro fator = 2; fator <= n; fator++) {
        enquanto (n % fator == 0) {
            multi = multi +1
            n = n / fator
        }

        se (multi > 0) {
            escreva(fator, " com multiplicidade ", multi)
        }
    }
  }

}

