import java.time.LocalDateTime;

public class Admin extends User {
  private LocalDateTime dataPromocao;

  public Admin(String nome, String username, String email) {
    super(nome, username, email);
    this.dataPromocao = LocalDateTime.now();
  }

  @Override
  public boolean podeApagarMensagem(User autor) {
    return true;
  }

  @Override
  public boolean podeEditarGrupo() {
    return true;
  }

  @Override
  public boolean podeApagarGrupo() {
    return true;
  }

  public LocalDateTime getDataPromocao() {
    return this.dataPromocao;
  }

  @Override
  public String obterInfo() {
    return super.obterInfo() + " [ADMIN]";
  }
}
