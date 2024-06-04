programa {
  funcao inicio() {
    inteiro a, b

    escreva("Entre com o valor A: ")
    leia(a)

    b = a/100

    se (b%2 == 0) {
      escreva("par")
    } senao {
      escreva("ímpar")
    }
  }
}
