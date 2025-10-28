class Veiculo {
    private String marca;
    private String modelo;
    private int ano;
    private String placa;
    private String cor;
    private TipoVeiculo tipo;
    private Cliente cliente;

    Veiculo(String marca, String modelo, int ano, String placa, String cor, TipoVeiculo tipo, Cliente cliente) {
        this.marca = marca;
        this.modelo = modelo;
        this.ano = ano;
        this.placa = placa;
        this.cor = cor;
        this.tipo = tipo;
        this.cliente = cliente;
    }

    public String getMarca() {
        return marca;
    }

    public String getModelo() {
        return modelo;
    }

    public int getAno() {
        return ano;
    }

    public String getPlaca() {
        return placa;
    }

    public String getCor() {
        return cor;
    }

    public TipoVeiculo getTipo() {
        return tipo;
    }

    public Cliente getCliente() {
        return cliente;
    }
}