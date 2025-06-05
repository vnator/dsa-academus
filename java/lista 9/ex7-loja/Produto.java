public class Produto {
  private String nome;
  private double preco;

  public Produto(String nome, double preco) {
    this.nome = nome;
    this.preco = preco;
  }

  @Override
  public String toString() {
    return "nome: " + nome + "; R$: " + preco;
  }

  public String getNome() { return nome; }
  public double getPreco() { return preco; }
}
