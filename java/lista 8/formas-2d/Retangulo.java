public class Retangulo extends TwoDShape {
  
  public boolean isSquare() {
    return this.getAltura() == this.getLargura();
  }

  public double getArea() {
    return this.getAltura() * this.getLargura();
  }

}
