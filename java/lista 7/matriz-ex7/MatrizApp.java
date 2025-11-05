public class MatrizApp {
  public static void main(String[] args) {
    int[] valores = {
      0, 1, 2,
      3, 4, 5,
      6, 7, 8
    };

    Matriz matriz = new Matriz(valores);
    matriz.print();
  }
}
