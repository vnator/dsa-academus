public abstract class Shape {
  protected String nome;

  public Shape(String nome) {
    this.nome = nome;
  }

  public abstract double calcularArea();

  public abstract double calcularPerimetro();

  public String getNome() {
    return this.nome;
  }

  public void imprimirInfo() {
    System.out.println("\n" + this.nome);
    System.out.println("Área: " + String.format("%.2f", this.calcularArea()));
    System.out.println("Perímetro: " + String.format("%.2f", this.calcularPerimetro()));
  }
}
