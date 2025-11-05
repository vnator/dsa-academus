public class Retangulo {

  private double comprimento;
  private double largura;
  private double perimetro;
  private double area;


  public Retangulo () {
    comprimento = 1;
    largura = 1;
  }

  public Retangulo (double comprimento, double largura) {
    this.comprimento = comprimento;
    this.largura = largura;
  }

  public void calcArea() {
    area = comprimento * largura;
  }

  public void calcPerimetro() {
    perimetro = 2 * (comprimento + largura);
  }

  public void printArea() {
    System.out.println("Area Retangulo: " + area);
  }

  public void printPerimetro() {
    System.out.println("Perimetro Retangulo: " + perimetro);
  }

  public double getComprimento() {
    return comprimento;
  }

  public double getLargura() {
    return largura;
  }
}
