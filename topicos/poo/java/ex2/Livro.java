import java.util.ArrayList;
import java.util.List;

public class Livro {
  private String ISBN;
  private String titulo;
  private String autor;
  private List<Leitor> leitores;

  public Livro(String ISBN, String titulo, String autor) {
    this.ISBN = ISBN;
    this.titulo = titulo;
    this.autor = autor;
    this.leitores = new ArrayList<>();
  }

  public void incluirLeitor(Leitor leitor) {
    if (!this.leitores.contains(leitor)) {
      this.leitores.add(leitor);
    }
  }

  public void imprimirLeitores() {
    for (Leitor leitor : this.leitores) {
      System.out.println("\n" + leitor.getNome() + " leu " + this.titulo + ".");
    }
  }

  public String getTitulo() {
    return this.titulo;
  }

  public String getAutor() {
    return this.autor;
  }

  public String getISBN() {
    return this.ISBN;
  }
}
