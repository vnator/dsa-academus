class Mecanico extends Pessoa {
    private TipoVeiculo especialidade;
    private double salario;

    Mecanico(String nome, int idade, String cpf, TipoVeiculo especialidade, double salario) {
        super(nome, idade, cpf);
        this.especialidade = especialidade;
        this.salario = salario;
    }

    public TipoVeiculo getEspecialidade() {
        return especialidade;
    }
    public double getSalario() {
        return salario;
    }

    public void setEspecialidade(TipoVeiculo especialidade) {
        this.especialidade = especialidade;
    }

    public void setSalario(double salario) {
        this.salario = salario;
    }
}