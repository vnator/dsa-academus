programa {
  // Escreva um algoritmo que leia um n�mero inteiro positivo, n, e uma sequ�ncia de n n�meros
  // inteiros, determine e escreva a quantidade de segmentos de n�meros iguais consecutivos que
  // comp�em essa sequ�ncia. Por exemplo, para n=9 e a sequ�ncia 5, 2, 2, 4, 4, 4, 4, 1, 1,
  // ent�o a sa�da deve ser o n�mero 4, pois
  // 5, 2, 2, 4, 4, 4, 4, 1, 1
  // possui quatro segmentos de n�meros iguais consecutivos:
  funcao inicio() {
    inteiro a, i = 0, vetor[10], segmentos = 1

    escreva("Escreva um n�mero inteiro: ")
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

