public class MensagemImagem extends Mensagem {
    private String urlImagem;

    public MensagemImagem(String urlImagem) {
        this.urlImagem = urlImagem;
    }

    @Override
    public String toString() {
        return "Imagem: " + urlImagem;
    }
}