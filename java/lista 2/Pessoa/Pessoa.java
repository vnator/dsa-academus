public class Pessoa {
    private String nome;
    private String telefone;

    public void setNome(String nome) {
        this.nome = nome;
    }

    public void setTelefone(String telefone) {
        this.telefone = telefone;
    } 

    public void exibeDados() {
        System.out.println("nome: " + nome + ", telefone: " + telefone);
    }
}