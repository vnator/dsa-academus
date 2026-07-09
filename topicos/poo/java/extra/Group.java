import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

public class Group {
  private String nome;
  private String descricao;
  private User criador;
  private List<User> membros;
  private List<Message> mensagens;
  private LocalDateTime dataCriacao;

  public Group(String nome, String descricao, User criador) {
    this.nome = nome;
    this.descricao = descricao;
    this.criador = criador;
    this.membros = new ArrayList<>();
    this.mensagens = new ArrayList<>();
    this.dataCriacao = LocalDateTime.now();
    this.membros.add(criador);
  }

  public boolean adicionarMembro(User usuario) {
    if (!this.membros.contains(usuario)) {
      this.membros.add(usuario);
      return true;
    }
    return false;
  }

  public boolean removerMembro(User admin, User usuario) {
    if (admin.podeEditarGrupo()) {
      return this.membros.remove(usuario);
    }
    return false;
  }

  public boolean enviarMensagem(User autor, Message mensagem) {
    if (this.membros.contains(autor) && autor.podeEnviarMensagem()) {
      this.mensagens.add(mensagem);
      return true;
    }
    return false;
  }

  public boolean apagarMensagem(User usuario, int indice) {
    if (indice >= 0 && indice < this.mensagens.size()) {
      Message msg = this.mensagens.get(indice);
      // Admin pode apagar qualquer mensagem, usuário só a sua
      if (usuario.podeEditarGrupo() || msg.getAutor().equals(usuario.getUsername())) {
        this.mensagens.remove(indice);
        return true;
      }
    }
    return false;
  }

  public Message obterMensagem(int indice) {
    if (indice >= 0 && indice < this.mensagens.size()) {
      return this.mensagens.get(indice);
    }
    return null;
  }

  public void exibirHistorico() {
    System.out.println("\n=== Histórico de Mensagens: " + this.nome + " ===");
    if (this.mensagens.isEmpty()) {
      System.out.println("Nenhuma mensagem ainda.");
    } else {
      for (int i = 0; i < this.mensagens.size(); i++) {
        System.out.println("[" + i + "] " + this.mensagens.get(i).exibir());
      }
    }
  }

  public void exibirInfo() {
    System.out.println("\n=== Informações do Grupo ===");
    System.out.println("Grupo: " + this.nome);
    System.out.println("Descrição: " + this.descricao);
    System.out.println("Criador: " + this.criador.obterInfo());
    DateTimeFormatter formatter = DateTimeFormatter.ofPattern("dd/MM/yyyy HH:mm");
    System.out.println("Criado em: " + this.dataCriacao.format(formatter));
    System.out.println("Total de membros: " + this.membros.size());
    System.out.println("Total de mensagens: " + this.mensagens.size());
  }

  public void exibirMembros() {
    System.out.println("\n=== Membros do Grupo ===");
    for (int i = 0; i < this.membros.size(); i++) {
      System.out.println((i + 1) + ". " + this.membros.get(i).obterInfo());
    }
  }

  public String getNome() {
    return this.nome;
  }

  public String getDescricao() {
    return this.descricao;
  }

  public User getCriador() {
    return this.criador;
  }

  public List<User> getMembros() {
    return new ArrayList<>(this.membros);
  }

  public List<Message> getMensagens() {
    return new ArrayList<>(this.mensagens);
  }

  public int getTotalMensagens() {
    return this.mensagens.size();
  }

  public int getTotalMembros() {
    return this.membros.size();
  }
}
