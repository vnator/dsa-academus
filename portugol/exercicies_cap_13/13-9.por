programa {
  inclua biblioteca Texto --> tx
//   . Escreva um algoritmo para ler um número inteiro positivo, n, e escrever os dígitos de n,
// da esquerda para a direita, separados por um espaço. Por exemplo, se n = 2439, então a
// saída do algoritmo deveria ser 2 4 3 9.
  funcao inicio() {
    inteiro a, i = 0

    escreva("Escreva um número inteiro: ")
    leia(a)

    enquanto (a <= 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(a)
    }

    cadeia n = ""+a, resultado = ""

    faca {
      resultado = resultado + " " + tx.obter_caracter(n, i)
      i = i+1
    } enquanto (i < tx.numero_caracteres(n))
    escreva(resultado)
  }

}

