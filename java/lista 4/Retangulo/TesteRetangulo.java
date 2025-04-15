public class TesteRetangulo {
    public static void main(String[] args) {
        Retangulo retangulo1 = new Retangulo();
        Retangulo retangulo2 = new Retangulo(3, 4);

        System.out.println("Retângulo 1 (Construtor sem parâmetros):");
        System.out.println("Largura: " + retangulo1.getLargura());
        System.out.println("Comprimento: " + retangulo1.getComprimento());
        retangulo1.calcArea();
        retangulo1.calcPerimetro();
        retangulo1.printArea();
        retangulo1.printPerimetro();

        System.out.println("\nRetângulo 2 (Construtor com parâmetros):");
        System.out.println("Largura: " + retangulo2.getLargura());
        System.out.println("Comprimento: " + retangulo2.getComprimento());
        retangulo2.calcArea();
        retangulo2.calcPerimetro();
        retangulo2.printArea();
        retangulo2.printPerimetro();
    }
}
