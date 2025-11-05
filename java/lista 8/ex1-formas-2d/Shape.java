public class Shape {
  public static void main(String[] args) {
    Triangulo t1 = new Triangulo();
    Triangulo t2 = new Triangulo();


    Retangulo r1 = new Retangulo();
    Retangulo r2 = new Retangulo();

    t1.setLargura(4.0);
    t1.setAltura(4.0);
    t1.setEstilo("cheio");

    t2.setLargura(8.0);
    t2.setAltura(12.0);
    t2.setEstilo("contorno");

    r1.setAltura(20.0);
    r1.setLargura(20.0);
 
    r2.setAltura(2.3);
    r2.setLargura(3.2);
  
    System.out.println("Info para T1");
    t1.mostrarEstilo();
    t1.mostrarDim();
    System.out.println("Area: " + t1.getArea());
 
    System.out.println("\nInfo para T2");
    t2.mostrarEstilo();
    t2.mostrarDim();
    System.out.println("Area: " + t2.getArea());
  

    System.out.println("\nInfo para R1");
    r1.mostrarDim();
    System.out.println("Area: " + r1.getArea());
    System.out.println("É quadrado? " + (r1.isSquare() ? "sim" : "não"));
  

    System.out.println("\nInfo para R2");
    r1.mostrarDim();
    System.out.println("Area: " + r2.getArea());
    System.out.println("É quadrado? " + (r2.isSquare() ? "sim" : "não"));
  }
}
