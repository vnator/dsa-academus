programa {
  inclua biblioteca Matematica --> mat
  funcao inicio() {
//     O n�mero 3025 goza da seguinte propriedade
// 
//     30 + 25 = 55
//     552
//     = 3025
//     Escreva um algoritmo determine e escreva todos os n�meros de quatro d�gitos que possuem
//     a propriedade acima. Note que este algoritmo n�o possui nenhum dado de entrada.

    inteiro a = 1000, b = 9999, un, dz, cn, ml, val_1, val_2, soma, raiz


    faca {
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
          a,
          " =  ",
          val_1,
          " + ",
          val_2,
          " => ",
          soma,
          "� =",
          a,
          "\n")
      }

      a = a+1
    } enquanto (a <= b)
  }
}

