public class Carro extends Veiculo {
    private int ano;

    public Carro(String modelo, double preco, int ano) {
        super(modelo, preco);
        this.ano = ano;
    }

    public int getAno() {
        return ano;
    }

    @Override
    public void printDados() {
        super.printDados();
        System.out.println("Ano: " + ano);
    }

    @Override
    public String toString() {
        return "Carro{" +
               "modelo='" + super.getModelo() + '\'' +
               ", preco=" + super.getPreco() +
               ", ano=" + ano +
               "} ";
    }
}
