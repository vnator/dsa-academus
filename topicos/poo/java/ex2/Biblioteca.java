import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class Biblioteca {
  private List<Livro> colecao;
  private List<Emprestimo> emprestimos;

  public Biblioteca() {
    this.colecao = new ArrayList<>();
    this.emprestimos = new ArrayList<>();
  }

  public Biblioteca(List<Livro> livros) {
    this.colecao = new ArrayList<>(livros);
    this.emprestimos = new ArrayList<>();
  }

  public void addLivroColecao(Livro livro) {
    this.colecao.add(livro);
  }

  public Emprestimo registraEmprestimo(Livro livro, Leitor leitor) {
    Emprestimo emprestimo = new Emprestimo(livro, leitor, new Date());
    this.emprestimos.add(emprestimo);
    leitor.setLivro(livro);
    return emprestimo;
  }

  public Livro buscarLivro(String autor) {
    for (Livro livro : this.colecao) {
      if (livro.getAutor().equals(autor)) {
        return livro;
      }
    }
    return null;
  }

  private static class Emprestimo {
    private Livro livro;
    private Leitor leitor;
    private Date momento;

    public Emprestimo(Livro livro, Leitor leitor, Date momento) {
      this.livro = livro;
      this.leitor = leitor;
      this.momento = momento;
    }
  }
}
