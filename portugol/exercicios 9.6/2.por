programa {
  funcao inicio() {
    cadeia entrada

    escreva("Digite nome do seu time: \n(Primeira letra deve ser mai�scula, nao precisa do acento)\n")
    leia(entrada)

    se (
      entrada == "Flamengo"
      ou entrada == "Fluminense"
      ou entrada == "Vasco"
      ou entrada == "Botafogo"
    ) {
      escreva(entrada, " � um time carioca")
    } senao se (
      entrada == "Sao Paulo"
      ou entrada == "Palmeiras"
      ou entrada == "Santos"
      ou entrada == "Corinthians"
    ) {
      escreva(entrada, " � um time paulista")
    } senao {
      escreva(entrada, " time desconhecido")
    }
  }
}
