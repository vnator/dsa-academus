programa {
  funcao inicio() {
    inteiro a, b


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
      se (a%2 != 0) {
        escreva("\n ", a*a)
      }
      
      a = a+1
    }
  }
}
