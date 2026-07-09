import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class VideoMessage implements Message {
  private String conteudo;
  private String autor;
  private LocalDateTime horario;
  private String nomeArquivo;
  private double tamanhoMB;
  private int duracaoSegundos;
  private static final String TIPO = "Vídeo";

  public VideoMessage(String nomeArquivo, double tamanhoMB, int duracaoSegundos, String autor) {
    this.nomeArquivo = nomeArquivo;
    this.tamanhoMB = tamanhoMB;
    this.duracaoSegundos = duracaoSegundos;
    this.conteudo = "[Vídeo: " + nomeArquivo + " (" + String.format("%.2f", tamanhoMB) + 
                   "MB, " + formatarDuracao(duracaoSegundos) + ")]";
    this.autor = autor;
    this.horario = LocalDateTime.now();
  }

  private static String formatarDuracao(int segundos) {
    int minutos = segundos / 60;
    int segs = segundos % 60;
    return minutos + "m" + segs + "s";
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
    return "[" + this.horario.format(formatter) + "] 🎥 " + 
           this.autor + ": " + this.conteudo;
  }

  public String getNomeArquivo() {
    return this.nomeArquivo;
  }

  public double getTamanhoMB() {
    return this.tamanhoMB;
  }

  public int getDuracaoSegundos() {
    return this.duracaoSegundos;
  }
}
