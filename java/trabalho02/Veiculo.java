public class Veiculo {
  private String modelo;
  private double preco;

  public Veiculo(String modelo, double preco) {
    this.modelo = modelo;
    this.preco = preco;
  }

  public double getPreco() {
    return preco;
  }

  public String getModelo() {
    return modelo;
  }

  public void printDados() {
    System.out.println("Modelo: " + modelo);
    System.out.println("Preço: R$ " + preco);
  }

  @Override
  public String toString() {
    return "Veiculo{" +
           "modelo='" + modelo + '\'' +
           ", preco=" + preco +
           "} ";
  }
}
