programa {
  funcao inicio() {
    inteiro a, b, r = 0, i = 1


    escreva("Escreva o primeiro numero: ")
    leia(a)

    enquanto (a <= 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(a)
    }

    escreva("Escreva o segundo numero numero: ")
    leia(b)

    enquanto (b <= a) {
      escreva("Erro: Digite um valor maior que b: ")
      leia(b)
    }

    enquanto (a <= b) {
      se (a%2 == 0) {
        r = r+a
        i = i+1
      }

      a = a+1
    }

    escreva(r/2)
  }
}
