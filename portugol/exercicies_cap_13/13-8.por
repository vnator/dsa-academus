programa {
  // Um n�mero inteiro positivo, n, � dito triangular se, e somente se, ele � o resultado do
  // produto de tr�s n�meros inteiros positivos e consecutivos. Por exemplo, 24 � triangular,
  // pois 24 = 2 � 3 � 4. Agora, escreva um algoritmo que leia um n�mero inteiro positivo, n,
  // e escreva como sa�da �� triangular� se n for triangular e �n�o � triangular� caso contr�rio.
  funcao inicio() {
    inteiro a, i = 0, prod = 0

    escreva("Escreva um n�mero inteiro: ")
    leia(a)

    enquanto (a <= 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(a)
    }

    faca {
      prod = i * (i+1) * (i+2)

      se (prod == a) {
        escreva(prod, " � triangular")
      }

      i = i+1
    } enquanto (prod < a)

    escreva(a, " n�o � triangular")
  }

}

