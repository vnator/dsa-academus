public class Aluno {
  private String nome;
  private int codigo;

  public Aluno(String nome, int codigo) {
    this.nome = nome;
    this.codigo = codigo;
  }

  public void print() {
    System.out.println("Nome: " + nome + ", Código: " + codigo);
  }
}
