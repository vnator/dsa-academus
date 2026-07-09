public class User {
  private String nome;
  private String username;
  private String email;
  private boolean ativo;

  public User(String nome, String username, String email) {
    this.nome = nome;
    this.username = username;
    this.email = email;
    this.ativo = true;
  }

  public boolean podeEnviarMensagem() {
    return this.ativo;
  }

  public boolean podeApagarMensagem(User autor) {
    return this.username.equals(autor.getUsername());
  }

  public boolean podeEditarGrupo() {
    return false;
  }

  public boolean podeApagarGrupo() {
    return false;
  }

  public String getNome() {
    return this.nome;
  }

  public String getUsername() {
    return this.username;
  }

  public String getEmail() {
    return this.email;
  }

  public boolean isAtivo() {
    return this.ativo;
  }

  public void setAtivo(boolean ativo) {
    this.ativo = ativo;
  }

  public String obterInfo() {
    return this.nome + " (@" + this.username + ")";
  }
}
