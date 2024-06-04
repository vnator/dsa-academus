programa {
  // Um número inteiro positivo, n, é dito triangular se, e somente se, ele é o resultado do
  // produto de três números inteiros positivos e consecutivos. Por exemplo, 24 é triangular,
  // pois 24 = 2 × 3 × 4. Agora, escreva um algoritmo que leia um número inteiro positivo, n,
  // e escreva como saída “é triangular” se n for triangular e “não é triangular” caso contrário.
  funcao inicio() {
    inteiro a, i = 0, prod = 0

    escreva("Escreva um número inteiro: ")
    leia(a)

    enquanto (a <= 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(a)
    }

    faca {
      prod = i * (i+1) * (i+2)

      se (prod == a) {
        escreva(prod, " é triangular")
      }

      i = i+1
    } enquanto (prod < a)

    escreva(a, " não é triangular")
  }

}

