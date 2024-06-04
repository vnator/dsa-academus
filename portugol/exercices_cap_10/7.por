programa {
  inclua biblioteca Matematica --> mat
  funcao inicio() {
    // Qualquer número inteiro positivo de quatro algarismos pode ser dividido em duas dezenas
    // formadas pelos seus dois primeiros e dois últimos dígitos. Por exemplo,
    // 1297 : 12 e 97.
    // 5314 : 53 e 14.
    // Escreva um algoritmo que imprima todos os números de quatro algarismos cuja raiz qua-
    // drada seja a soma das dezenas formadas pela divisão acima. Por exemplo,
    // √9801 = 99 = 98 + 01 .
    // Portanto, 9801 é um dos números a serem escritos pelo algoritmo. Note que este algoritmo
    // não possui nenhum dado de entrada!

    inteiro a = 1000, b = 9999, un, dz, cn, ml, val_1, val_2, soma, raiz


    enquanto (a <= b) {
      ml = a/1000
      cn = (a-(ml*1000))/100
      dz = (a-(ml*1000+cn*100))/10
      un = a-(ml*1000)+(cn*100)+(dz*10)
      
      val_1 = ml*10+cn
      val_2 = dz*10+un

      raiz = mat.raiz(a, 2)
      soma = val_1 + val_2

      se (raiz == soma e mat.potencia(raiz, 2) == a) {
        escreva(
          "A soma das duas primeiras dezenas de ",
          a,
          ", que são ",
          val_1,
          " e ",
          val_2,
          " é ",
          soma,
          " que é o mesmo valor de ",
          raiz,
          " sendo este a raiz quadrada de ",
          a,
          "\n")
      }

      a = a+1
    }
  }
}

