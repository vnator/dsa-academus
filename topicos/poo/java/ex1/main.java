public class main {
  public static void main(String[] args) {
    Livro livro_1 = new Livro("1234", "O senhor dos Aneis", "JRR Tolkien");
    Livro livro_2 = new Livro("4231", "O nome do Vento", "Patrick Ruthfuss");

    Leitor leitor_1 = new Leitor(29, "Joao Henrique Serodio", livro_1);
    Leitor leitor_2 = new Leitor(48, "Adriano Curuja", livro_2);

    livro_1.putLeitor(leitor_1);
    livro_2.putLeitor(leitor_2);
    livro_2.putLeitor(leitor_1);

    leitor_1.oqueEstalendo();
    leitor_2.oqueEstalendo();

    livro_1.printLeitores();
    livro_2.printLeitores();
  }
}
