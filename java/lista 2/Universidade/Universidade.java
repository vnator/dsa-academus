public class Universidade {
    private String nome;
    private String cidade;
    private String estado;


    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setCidade(String cidade) {
        this.cidade = cidade;
    }

    public void setEstado(String estado) {
        this.estado = estado;
    }

    public void exibeDados() {
        System.out.println("univerdidade: " + nome + ", cidade: " + cidade + " - " + estado);
    }
}