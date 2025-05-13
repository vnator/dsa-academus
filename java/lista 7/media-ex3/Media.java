public class Media {

  public static void main(String[] args) {
    
    double[] notas = {7.5, 8.0, 6.5, 9.0, 10.0};


    for (int i = 0; i < notas.length; i++) {
      System.out.println("Nota " + (i + 1) + ": " + notas[i]);
    }

    double media = calcularMedia(notas);
    System.out.println("A média das notas é: " + media);
  }
    

  public static double calcularMedia(double[] notas) {
    double soma = 0;

    for (int i = 0; i < notas.length; i++) {
      soma += notas[i];
    }

    return soma / notas.length;
  }
}
