public class main {
  public static void main(String[] args) {
    Biblioteca biblioteca = new Biblioteca();

    // livros
    Livro livro_1 = new Livro("1234", "O senhor dos Aneis", "JRR Tolkien");
    Livro livro_2 = new Livro("2342d", "A arte de ler e meditar", "Hugo de Sao Vitor");

    biblioteca.addLivroColecao(livro_1);
    biblioteca.addLivroColecao(livro_2);

    // leitores
    Leitor leitor_1 = new Leitor(29, "Nereu de Oliveira", livro_1);
    Leitor leitor_2 = new Leitor(36, "Joao Henrique Serodio", livro_2);

    biblioteca.registraEmprestimo(livro_1, leitor_1);
    biblioteca.registraEmprestimo(livro_2, leitor_2);

    // livro 2 tambem foi lido por leitor_1
    biblioteca.registraEmprestimo(livro_2, leitor_1);

    Livro livroBuscado = biblioteca.buscarLivro("Hugo de Sao Vitor");

    if (livroBuscado != null) {
      System.out.println("Livro encontrado: " + livroBuscado.getTitulo() + ".");
    }

    leitor_1.oqueEstaLendo();
    leitor_2.oqueEstaLendo();

    // lista de livros
    livro_1.imprimirLeitores();
    livro_2.imprimirLeitores();
  }
}
