public class SomaApp {
  public static void main(String args[]) {
    int argumentos[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int argumentos2[] = {11, 12, 13, 14, 15};

    Soma soma = new Soma(argumentos);
    Soma soma2 = new Soma(argumentos2);

    System.out.println("Soma dos elementos do primeiro array: " + soma.calc());
    System.out.println("Soma dos elementos do segundo array: " + soma2.calc());
  }
}
