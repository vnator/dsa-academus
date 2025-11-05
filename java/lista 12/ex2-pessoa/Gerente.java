public class Gerente extends Pessoa {
    private String departamento;

    public Gerente(String nome, int idade, String departamento) {
        super(nome, idade);
        this.departamento = departamento;
    }

    public String getDepartamento() {
        return departamento;
    }

    @Override
    public String toString() {
        return "Gerente: " + getNome() + ", Idade: " + getIdade() + ", Departamento: " + departamento;
    }
}