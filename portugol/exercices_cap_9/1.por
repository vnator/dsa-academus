programa {
  funcao inicio() {
    inteiro entrada

    escreva("Digite um numero\n")
    leia(entrada)

    se (entrada%3 == 0 e entrada%7 == 0) {
      escreva(entrada, " é divisivel por 3 e 7")
    } senao {
      escreva(entrada, " não é divisivel por 3 e 7")
    }
  }
}
