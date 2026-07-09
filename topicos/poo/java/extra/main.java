import java.util.List;

public class main {
  public static void main(String[] args) {
    // Criando usuários
    User joao = new User("João Silva", "joao_silva", "joao@email.com");
    User maria = new User("Maria Santos", "maria_santos", "maria@email.com");
    User pedro = new User("Pedro Oliveira", "pedro_oliveira", "pedro@email.com");
    
    // Criando admin
    Admin admin = new Admin("Carlos Admin", "carlos_admin", "carlos@email.com");

    System.out.println("=== Aplicação de Mensagens ===");
    System.out.println("\nUsuários criados:");
    System.out.println("1. " + joao.obterInfo());
    System.out.println("2. " + maria.obterInfo());
    System.out.println("3. " + pedro.obterInfo());
    System.out.println("4. " + admin.obterInfo());

    // Criando grupos
    Group grupoTrabalho = new Group(
        "Grupo Trabalho",
        "Discussões sobre o projeto da empresa",
        admin
    );

    Group grupoAmigos = new Group(
        "Grupo Amigos",
        "Conversa entre amigos",
        joao
    );

    // Adicionando membros aos grupos
    grupoTrabalho.adicionarMembro(joao);
    grupoTrabalho.adicionarMembro(maria);
    grupoTrabalho.adicionarMembro(pedro);

    grupoAmigos.adicionarMembro(maria);
    grupoAmigos.adicionarMembro(pedro);

    // Exibindo informações dos grupos
    grupoTrabalho.exibirInfo();
    grupoTrabalho.exibirMembros();

    // Enviando mensagens no grupo de trabalho
    System.out.println("\n=== Enviando Mensagens - Grupo Trabalho ===");

    Message msg1 = new TextMessage("Olá pessoal, vamos começar o projeto?", admin.getUsername());
    Message msg2 = new TextMessage("Eu estou pronto para começar!", joao.getUsername());
    Message img1 = new ImageMessage("diagrama_projeto.png", 2.5, maria.getUsername());
    Message msg3 = new TextMessage("Ótimo diagrama Maria! Vamos usar isso.", pedro.getUsername());

    grupoTrabalho.enviarMensagem(admin, msg1);
    grupoTrabalho.enviarMensagem(joao, msg2);
    grupoTrabalho.enviarMensagem(maria, img1);
    grupoTrabalho.enviarMensagem(pedro, msg3);

    // Enviando mensagens no grupo de amigos
    System.out.println("\n=== Enviando Mensagens - Grupo Amigos ===");

    Message msg4 = new TextMessage("Oi pessoal! Como estão?", joao.getUsername());
    Message audio1 = new AudioMessage("risada.mp3", 0.8, 5, maria.getUsername());
    Message video1 = new VideoMessage("video_noturna.mp4", 25.3, 120, pedro.getUsername());
    Message msg5 = new TextMessage("Que noite incrível! 😄", joao.getUsername());

    grupoAmigos.enviarMensagem(joao, msg4);
    grupoAmigos.enviarMensagem(maria, audio1);
    grupoAmigos.enviarMensagem(pedro, video1);
    grupoAmigos.enviarMensagem(joao, msg5);

    // Exibindo histórico de mensagens
    grupoTrabalho.exibirHistorico();
    grupoAmigos.exibirHistorico();

    // Testando permissões
    System.out.println("\n=== Testando Permissões ===");
    System.out.println("\nTentando apagar mensagem:");
    System.out.println("João apagando sua própria mensagem: " + 
        grupoTrabalho.apagarMensagem(joao, 1));
    System.out.println("Maria tentando apagar mensagem de João: " + 
        grupoTrabalho.apagarMensagem(maria, 0));
    System.out.println("Admin apagando qualquer mensagem: " + 
        grupoTrabalho.apagarMensagem(admin, 0));

    // Exibindo histórico após deletar
    grupoTrabalho.exibirHistorico();

    // Testando desativação de usuário
    System.out.println("\n=== Testando Desativação ===");
    maria.setAtivo(false);
    System.out.println("Maria foi desativada");
    
    Message tentativaMensagem = new TextMessage("Tentando enviar mensagem", maria.getUsername());
    System.out.println("Tentando enviar mensagem com Maria desativada: " + 
        grupoAmigos.enviarMensagem(maria, tentativaMensagem));

    // Resumo final
    System.out.println("\n=== Resumo Final ===");
    System.out.println("Grupo Trabalho: " + grupoTrabalho.getTotalMensagens() + 
        " mensagens, " + grupoTrabalho.getTotalMembros() + " membros");
    System.out.println("Grupo Amigos: " + grupoAmigos.getTotalMensagens() + 
        " mensagens, " + grupoAmigos.getTotalMembros() + " membros");

    // Estatísticas por tipo de mensagem
    contarMensagensporTipo(grupoTrabalho.getMensagens());
    contarMensagensporTipo(grupoAmigos.getMensagens());
  }

  private static void contarMensagensporTipo(List<Message> mensagens) {
    int texto = 0, imagem = 0, video = 0, audio = 0;
    
    for (Message msg : mensagens) {
      switch (msg.getTipo()) {
        case "Texto":
          texto++;
          break;
        case "Imagem":
          imagem++;
          break;
        case "Vídeo":
          video++;
          break;
        case "Áudio":
          audio++;
          break;
      }
    }

    if (texto + imagem + video + audio > 0) {
      System.out.println("\nEstatísticas de mensagens:");
      if (texto > 0) System.out.println("  Texto: " + texto);
      if (imagem > 0) System.out.println("  Imagem: " + imagem);
      if (video > 0) System.out.println("  Vídeo: " + video);
      if (audio > 0) System.out.println("  Áudio: " + audio);
    }
  }
}
