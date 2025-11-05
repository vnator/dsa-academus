public class MensagemApp {
    public static void main(String[] args) {
        Mensagem[] mensagens = new Mensagem[3];
        mensagens[0] = new Mensagem();
        mensagens[1] = new MensagemTexto("Olá, tudo bem?");
        mensagens[2] = new MensagemImagem("https://exemplo.com/imagem.jpg");

        for (Mensagem m : mensagens) {
            System.out.println(m);
        }
    }
}