import java.util.ArrayList;
import java.util.List;

public class main {
  public static void main(String[] args) {
    List<Shape> formas = new ArrayList<>();

    // Criando diferentes formas geométricas
    Circle circulo = new Circle(5);
    Rectangle retangulo = new Rectangle(4, 6);
    Triangle triangulo = new Triangle(3, 4, 5);

    // Adicionando à lista
    formas.add(circulo);
    formas.add(retangulo);
    formas.add(triangulo);

    // Imprimindo informações de cada forma
    System.out.println("=== Cálculo de Áreas e Perímetros ===");
    for (Shape forma : formas) {
      forma.imprimirInfo();
    }

    // Calculando área total
    double areaTotal = 0;
    for (Shape forma : formas) {
      areaTotal += forma.calcularArea();
    }

    System.out.println("\n=== Resumo ===");
    System.out.println("Área total de todas as formas: " + String.format("%.2f", areaTotal));
    System.out.println("Total de formas: " + formas.size());

    // Exemplo de modificação
    System.out.println("\n=== Modificando o Retângulo ===");
    retangulo.setLargura(5);
    retangulo.setAltura(8);
    System.out.println("Retângulo modificado:");
    retangulo.imprimirInfo();
  }
}
