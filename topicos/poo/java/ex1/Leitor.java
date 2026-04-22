public class Leitor {
  int idade;
  String nome;
  Livro livro;

  public Leitor(int idade, String nome, Livro livro) {
    this.idade = idade;
    this.nome = nome;
    this.livro = livro;
  }

  public void oqueEstalendo() {
    System.out.println(
        this.nome + " esta lendo " +
            this.livro.titulo + " escrito por " +
            this.livro.autor);
  }
}
