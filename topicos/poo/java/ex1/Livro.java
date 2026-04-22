import java.util.ArrayList;
import java.util.List;

public class Livro {
  private String ISBN;
  String titulo, autor;
  List<Leitor> leitores;

  public Livro(String ISBN, String titulo, String autor) {
    this.ISBN = ISBN;
    this.titulo = titulo;
    this.autor = autor;
    this.leitores = new ArrayList<>();
  }

  public void putLeitor(Leitor leitor) {
    this.leitores.add(leitor);
  }

  public void printLeitores() {
    for (Leitor leitor : this.leitores) {
      System.out.println(leitor.nome + " esta lendo " + this.titulo);
    }
  }
}
