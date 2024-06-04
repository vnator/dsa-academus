programa {
  // Escreva um algoritmo que leia um inteiro positivo, n, e uma sequência com n números
  // inteiros e calcule e escreva o comprimento do maior segmento crescente da sequência. Por
  // exemplo, se a entrada for
  // 9
  // 5, 10, 3, 2, 4, 7, 9, 8, 5
  // então a saída é 4, pois
  // 2, 4, 7, 9
  // é um segmento crescente com comprimento máximo e igual a 4 da sequência
  funcao inicio() {
    inteiro a, i = 0, vetor[10], maisLongo = 1, distancia = 1

    escreva("Escreva um número inteiro: ")
    leia(a)

    enquanto (a < 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(a)
    }

    escreva("Escreva uma sequencia separado por ,")
    leia(vetor)

    para(inteiro i = 0; i < a; i++) {
			se (vetor[i] > vetor[i - 1]) {
            distancia = distancia+1
            se (distancia > maisLongo) {
                maisLongo = distancia
            }
        } senao {
            distancia = 1
        }
		}

    escreva("Maior comprimento encontrado: ", maisLongo)
  }

}

