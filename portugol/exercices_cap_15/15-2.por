programa {
  // Escreva um algoritmo que leia um número inteiro positivo, n, e uma sequência de n números
  // inteiros, determine e escreva a quantidade de segmentos de números iguais consecutivos que
  // compõem essa sequência. Por exemplo, para n=9 e a sequência 5, 2, 2, 4, 4, 4, 4, 1, 1,
  // então a saída deve ser o número 4, pois
  // 5, 2, 2, 4, 4, 4, 4, 1, 1
  // possui quatro segmentos de números iguais consecutivos:
  funcao inicio() {
    inteiro a, i = 0, vetor[10], segmentos = 1

    escreva("Escreva um número inteiro: ")
    leia(a)

    enquanto (a < 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(a)
    }

    escreva("Escreva uma sequencia separado por ,")
    leia(vetor)

    para(inteiro i = 0; i < a; i++) {
			se (vetor[i] != vetor[i-1]) {
        segmentos = segmentos+1
      }
		}

    escreva("numero de Segmentos: ", segmentos)
  }

}

