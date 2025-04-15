public class Pontos2D {
  //atributos da classe, coordenadas do ponto no espaço bidimensional
  private double x, y;
  
  public Pontos2D () {
    x = 0;
    y = 0;
  }

  public Pontos2D (double x, double y) {
    this.x = x;
    this. y = y;
  } 

  public double getX() {
    return x;
  }

  public double getY() {
    return y;
  }
}
