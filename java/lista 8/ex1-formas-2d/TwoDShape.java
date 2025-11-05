public class TwoDShape {
  private double altura;
  private double largura;

  public double getAltura() {
    return altura;
  };
  
  public void setAltura(Double altura) {
    this.altura = altura;
  };

  public double getLargura() {
    return largura;
  };
  
  public void setLargura(Double largura) {
    this.largura = largura;
  };

  public void mostrarDim() {
    System.out.println("altura: " + altura + ", largura: " + largura);
  }
}
