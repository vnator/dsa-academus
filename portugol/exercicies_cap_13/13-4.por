programa {
  inclua biblioteca Matematica --> mat  // Inclui a biblioteca Matemática
  funcao inicio() {
    inteiro
      soma = 0,
      termo = 1,
      sinal = 1,
      i = 1,
      j = 1,
      limite = 50,
      fatorial = 1,
      div

    faca {
      faca {
        fatorial = fatorial * j
        j = j+1
      } enquanto (j <= i)
    
      div = mat.potencia(2, i) - 1
      termo = sinal * (fatorial / div)
      soma = soma + termo
      sinal = -sinal
      i = i+1
      fatorial = 1
      j = 1

    } enquanto (i <= limite)

    escreva("Soma: ", soma)
  }
}
