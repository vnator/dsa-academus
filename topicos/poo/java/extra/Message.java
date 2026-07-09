import java.time.LocalDateTime;

public interface Message {
  String getTipo();

  String getConteudo();

  String getAutor();

  LocalDateTime getHorario();

  String exibir();
}
