programa {
  funcao inicio() {
    inteiro n, i = 1, r = 0


    escreva("Escreva n: ")
    leia(n)

    enquanto (n <= 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(n)
    }

    enquanto (i < n) {
      se (n%i == 0) {
        r = r+i
      }

      i = i+1
    }

    se (n == r) {
      escreva("� perfeito ")
    } senao {
      escreva("n�o � perfeito ")
    }
  }
}
