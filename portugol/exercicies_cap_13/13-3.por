programa {
  inclua biblioteca Matematica --> mat  // Inclui a biblioteca Matemática
  // 3. Escreva um algoritmo que leia um inteiro positivo, n, e um valor real, x, e calcule e escreva
  // o somatório
  funcao inicio() {
    inteiro n, i = 1, soma = 0, sinal = 1, pot = 1
    real r


    escreva("Escreva um número inteiro: ")
    leia(n)

    enquanto (n <= 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(n)
    }

    escreva("Escreva um número real: ")
    leia(r)

    enquanto (r <= 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(r)
    }


    faca {
      soma = soma + (sinal * mat.potencia(r, i))
      sinal = -sinal
      i = i + 1
    } enquanto(i <=n)

    escreva("Somatório: ", soma)
  }
}
