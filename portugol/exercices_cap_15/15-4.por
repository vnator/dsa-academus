programa {
  // Sabe-se que um número inteiro positivo da forma n 3 é igual à soma de n números ímpares consecutivos
  funcao inicio() {
    inteiro m, soma = 0, impar = 1
    cadeia result = ""

    escreva("Escreva um número inteiro: ")
    leia(m)

    enquanto (m < 0) {
      escreva("Erro: Digite um valor positivo: ")
      leia(m)
    }

    para(inteiro n = 1; n <= m; n++) {
			para (inteiro i = 0; i < n; i++) {
            se (i > 0) {
                result = result + " + "
            }

            result = result + impar
            soma = soma + impar
            impar = impar + 2
        }

        console.log(n + "^3 = " + result + " = " + soma)
        soma = 0
        result = ""
		}
  }

}

