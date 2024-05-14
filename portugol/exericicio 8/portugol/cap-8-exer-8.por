
// Escreva um algoritmo para determinar se um aluno está aprovado ou reprovado em uma
// disciplina baseando-se em sua porcentagem de faltas, média parcial e nota do exame final.
// Um aluno para ser aprovado precisa cumprir as seguintes condições:
// • Sua porcentagem de faltas não deve ultrapassar 25%;
// • Sua média parcial deve ser igual ou maior que 7.0, ou a soma de sua média parcial e
// de sua nota do exame final deve ser igual ou maior que 10.0.
// Os valores de porcentagem de faltas, média parcial e nota do exame final do aluno devem ser
// lidos pelo algoritmo. A saída do algoritmo deve ser "aluno aprovado"ou "aluno reprovado".

programa {
  funcao inicio() {
    cadeia aluno
    inteiro porcentagem
    real media, exame

    escreva("Nome do Aluno\n")
    leia(aluno)

    escreva("Entre com a porcentagem de faltas\n")
    leia(porcentagem)

    escreva("Entre com a media parcial\n")
    leia(media)

    escreva("Entre com a nota do exame final\n")
    leia(exame)

    se (
      (porcentagem > 25)
      ou (
        (media < 7)
        e (media + exame < 10)
      )
    ) {
      escreva(aluno, " Reprovado")
    } senao {
      escreva(aluno, " Aprovado")
    }
  }
}
