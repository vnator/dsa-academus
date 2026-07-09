import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class ImageMessage implements Message {
  private String conteudo;
  private String autor;
  private LocalDateTime horario;
  private String nomeArquivo;
  private double tamanhoMB;
  private static final String TIPO = "Imagem";

  public ImageMessage(String nomeArquivo, double tamanhoMB, String autor) {
    this.nomeArquivo = nomeArquivo;
    this.tamanhoMB = tamanhoMB;
    this.conteudo = "[Imagem: " + nomeArquivo + " (" + String.format("%.2f", tamanhoMB) + "MB)]";
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
    return "[" + this.horario.format(formatter) + "] 🖼 " + 
           this.autor + ": " + this.conteudo;
  }

  public String getNomeArquivo() {
    return this.nomeArquivo;
  }

  public double getTamanhoMB() {
    return this.tamanhoMB;
  }
}
