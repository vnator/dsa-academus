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

    enquanto (i <= 2*n) {
      se (i%2==0) {
        escreva("\n ", i+1)
      }

      i = i+1
    }
  }
}
