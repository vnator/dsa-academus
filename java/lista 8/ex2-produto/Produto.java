public class Produto {
  protected String nome;
  protected double preco;

  public Produto(String nome, double preco) {
    this.nome = nome;
    this.preco = preco;
  }

  public boolean ehCaro() {
    return preco > 100.0;
  }

  public boolean ehCaro(int baseDeComparacao) {
    return preco > baseDeComparacao;
  }
}

