public class Matriz {
  private int[][] matriz = new int[3][3];

  public Matriz(int[] lista) {
    if (matriz.length == 3 && matriz[0].length == 3) {
      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          this.matriz[i][j] = lista[i * 3 + j];
        }
      }
    }
  }

  void print() {
    if (matriz.length == 3) {
      System.out.println("Imprimindo Matriz 3x3:\n");

      for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
          System.out.print(matriz[i][j] + "\t");
        }
        System.out.println(); // Quebra de linha após cada linha da matriz
      }
    }
  }
}
