public class Moto extends Veiculo {
  private double km;


  public Moto(String modelo, double preco, double km) {
    super(modelo, preco);
    this.km = km;
  }

  public double getKm() {
    return km;
  }

  @Override
  public void printDados() {
    super.printDados();
    System.out.println("Quilometragem: " + km + " km");
  }

  public String toString() {
    return "Moto{" +
           "modelo='" + super.getModelo() + '\'' +
           ", preco=" + super.getPreco() +
           ", km=" + km +
           "} ";
  }
}
