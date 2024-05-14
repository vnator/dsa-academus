programa {
  funcao inicio() {
    real entrada

    escreva("Digite um valor real ")
    leia(entrada)

    se (entrada == 20) {
      escreva(entrada, " = 20")
    } senao se (entrada > 20) {
      escreva(entrada, " > 20")
    } senao {
      escreva(entrada, " < 20")
    }
  }
}
