import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class TextMessage implements Message {
  private String conteudo;
  private String autor;
  private LocalDateTime horario;
  private static final String TIPO = "Texto";

  public TextMessage(String conteudo, String autor) {
    this.conteudo = conteudo;
    this.autor = autor;
    this.horario = LocalDateTime.now();
  }

  @Override
  public String getTipo() {
    return TIPO;
  }

  @Override
  public String getConteudo() {
    return this.conteudo;
  }

  @Override
  public String getAutor() {
    return this.autor;
  }

  @Override
  public LocalDateTime getHorario() {
    return this.horario;
  }

  @Override
  public String exibir() {
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("HH:mm:ss");
    return "[" + this.horario.format(formatter) + "] " + 
           this.autor + ": " + this.conteudo;
  }
}
