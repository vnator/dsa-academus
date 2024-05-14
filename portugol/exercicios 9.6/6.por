programa {
  funcao inicio() {
    inteiro val, un, dz, cn, ml, result

    escreva("Entre com o valor A (apenas 4 digitos): ")
    leia(val)

    ml = val/1000
    cn = (val-(ml*1000))/100
    dz = (val-(ml*1000+cn*100))/10
    un = val-(ml*1000)+(cn*100)+(dz*10)
    result = un + cn

    se (result%4 == 0) {
      escreva("sim ", result)
    } senao {
      escreva("nao ", result)
    }
  }
}
