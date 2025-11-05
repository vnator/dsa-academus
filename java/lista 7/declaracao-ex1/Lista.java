
public class Lista {

  public static void main (String[] args) {
    int[] meuArray1 = new int[10];
    int[] meuArray2 = {1, 2, 3, 4, 5};


    for (int i = 0; i < meuArray1.length; i++) {
      meuArray1[i] = (i + 1) * 10;
    }

  
    imprimeArray(meuArray1);
    imprimeArray(meuArray2);
  }

  public static void imprimeArray(int[] array) {
    for (int i = 0; i < array.length; i++) {
      System.out.print(array[i] + " ");
    }
    System.out.println();
  }
}
