public class Circle extends Shape {
  private double raio;

  public Circle(double raio) {
    super("Círculo");
    this.raio = raio;
  }

  @Override
  public double calcularArea() {
    return Math.PI * this.raio * this.raio;
  }

  @Override
  public double calcularPerimetro() {
    return 2 * Math.PI * this.raio;
  }

  public double getRaio() {
    return this.raio;
  }

  public void setRaio(double raio) {
    this.raio = raio;
  }
}
