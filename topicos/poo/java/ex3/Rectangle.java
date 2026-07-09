public class Rectangle extends Shape {
  private double largura;
  private double altura;

  public Rectangle(double largura, double altura) {
    super("Retângulo");
    this.largura = largura;
    this.altura = altura;
  }

  @Override
  public double calcularArea() {
    return this.largura * this.altura;
  }

  @Override
  public double calcularPerimetro() {
    return 2 * (this.largura + this.altura);
  }

  public double getLargura() {
    return this.largura;
  }

  public void setLargura(double largura) {
    this.largura = largura;
  }

  public double getAltura() {
    return this.altura;
  }

  public void setAltura(double altura) {
    this.altura = altura;
  }
}
