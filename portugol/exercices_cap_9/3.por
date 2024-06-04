programa {
  funcao inicio() {
    cadeia nome
    real salario, emprestimo, limite

    escreva("Digite nome do funcionário: ")
    leia(nome)

    escreva("\nDigite o Salário Bruto de ", nome, ": ")
    leia(salario)

    escreva("\nDigite o O valor do Emprestimo solicitado por ", nome, ": ")
    leia(emprestimo)

    limite = (salario*30)/100

    se (emprestimo <= limite) {
      escreva(nome, " teve o crédito concedido")
    } senao {
      escreva(nome, " teve o crédito negado")
    }
  }
}
