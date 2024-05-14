programa {
  funcao inicio() {
    inteiro n, i

    escreva("Escreva n: ")
    leia(n)

    enquanto (n <= 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(n)
    }

    para (inteiro k = 1; k <= n; k++) {
      para (i = 1; i <= 10; i++) {
        escreva(k, " x ", i, " = ", k*i, "\n")
      }
        escreva("\n ---------------------- \n ")
    }
  }
}
