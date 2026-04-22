public class Leitor {
  private int idade;
  private String nome;
  private Livro livro;

  public Leitor(int idade, String nome, Livro livro) {
    this.idade = idade;
    this.nome = nome;
    this.setLivro(livro);
  }

  public void oqueEstaLendo() {
    System.out.println(this.nome + " esta lendo " + this.livro.getTitulo() + " escrito por " + this.livro.getAutor());
  }

  public void setLivro(Livro livro) {
    this.livro = livro;
    this.livro.incluirLeitor(this);
  }

  public String getNome() {
    return this.nome;
  }

  public int getIdade() {
    return this.idade;
  }

  public Livro getLivro() {
    return this.livro;
  }
}
