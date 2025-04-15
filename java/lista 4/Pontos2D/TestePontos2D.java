public class TestePontos2D {
  public static void main(String[] args) {
    Pontos2D cartesiano_a = new Pontos2D();
    Pontos2D cartesiano_b = new Pontos2D(12.3, 43);

    System.out.println("Cartesiano A x: " + cartesiano_a.getX() + " Cartesiano A y:" + cartesiano_a.getY());
    System.out.println("Cartesiano B x: " + cartesiano_b.getX() + " Cartesiano B y:" + cartesiano_b.getY());
  }
}
