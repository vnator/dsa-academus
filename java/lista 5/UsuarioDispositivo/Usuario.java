public class Usuario {

  private String nome;
  private int matricula;
  private Dispositivo dispositivo;

  public Usuario(String nome, int matricula) {
    this.nome = nome;
    this.matricula = matricula;
  }

  public void setNome(String nome) {
    this.nome = nome;
  }

  public String getNome() {
    return nome;
  }

  public void setMatricula(int matricula) {
    this.matricula = matricula;
  }

  public int getMatricula() {
    return matricula;
  }
  
  public void setDispositivo(Dispositivo dispositivo) {
    this.dispositivo = dispositivo;
  }

  public void trabalhar () {
    System.out.print("\n" + nome + " esta ");
    dispositivo.usar();
  }
}
