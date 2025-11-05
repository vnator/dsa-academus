public class DVD extends Produto {
  private int duracaoMinutos;

  public DVD(String nome, double preco, int duracaoMinutos) {
    super(nome, preco);
    this.duracaoMinutos = duracaoMinutos;
  }

  @Override
  public String toString() {
    return "nome: " + getNome() + "; R$: " + getPreco() + "; duracao em minutos: " + duracaoMinutos;
  }
}
