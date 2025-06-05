public class Livro extends Produto {
  private String autor;
  private int paginas;

  public Livro(String nome, double preco, String autor, int paginas) {
    super(nome, preco);
    this.autor = autor;
    this.paginas = paginas;
  }

  public boolean ehExtenso() {
    return paginas > 100;
  }

  @Override
  public boolean ehCaro() {
    return preco > 50;
  }

  public String getAutor() {
    return autor;
  }

  public int getPaginas() {
    return paginas;
  }
}
