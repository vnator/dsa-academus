programa {
  funcao inicio() {
    inteiro i, n


    escreva("Um número Inteiro: ")
    leia(n)

    enquanto (n <= 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(n)
    }

    i = 1

    enquanto (i <= n) {
        escreva("\n ", i*i)

      i = i+1
    }
  }
}
