public class Dispositivo {
  private int codigo;
  private String nome;

  public Dispositivo(String nome, int codigo) {
    this.codigo = codigo;
    this.nome = nome;
  }
  
  public void usar() {
    System.out.print("usando o dispositivo " + nome);
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getNome() {
    return nome;
  }

  public void setCodigo(int codigo) {
    this.codigo = codigo;
  }

  public int getCodigo() {
    return codigo;
  }
}
