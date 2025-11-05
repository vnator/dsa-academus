public class MensagemTexto extends Mensagem {
    private String texto;

    public MensagemTexto(String texto) {
        this.texto = texto;
    }

    @Override
    public String toString() {
        return "Texto: " + texto;
    }
}