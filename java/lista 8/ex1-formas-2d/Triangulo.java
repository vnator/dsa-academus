public class Triangulo extends TwoDShape {
  private String estilo;

  public double getArea() {
    return (this.getAltura() * this.getLargura()) / 2;
  }

  public String getEstilo() {
    return estilo;
  }

  public void setEstilo(String estilo) {
    this.estilo = estilo;
  }

  public void mostrarEstilo() {
    System.out.println("Estilo: " + estilo);
  }
}
