public class Lista {
  int [] lista;
  int natural;

  public Lista(int []lista, int natural) {
    this.lista = lista;
    this.natural = natural;
  }

  public int getMaiorDiferencaConsecutiva() {
    int maiorDiferenca = 0;

    for (int i = 0; i < lista.length - 1; i++) {
      if (lista[i] > lista[i + 1]) {
        int diferenca = lista[i] - lista[i + 1];
        if (diferenca > maiorDiferenca) {
          maiorDiferenca = diferenca;
        }
      } else {
        int diferenca = lista[i + 1] - lista[i];
        if (diferenca > maiorDiferenca) {
          maiorDiferenca = diferenca;
        }
      }  
    }
    return maiorDiferenca;
  }

  public void tipoOrdenacao() {
    boolean creascente = true;
    boolean decrescente = true;
    

    for (int i = 0; i < lista.length - 1; i++) {
      if (lista[i] > lista[i + 1]) {
        creascente = false;
      } else if (lista[i] < lista[i + 1]) {
        decrescente = false;
      }
    }

    if (creascente) {
      System.out.println("Crescente");
    } else if (decrescente) {
      System.out.println("Decrescente");
    } else {
      System.out.println("Desordenada");
    }
  }

  public void comparaNatural() {

    int qtdMaiorQNatural = 0;
    int qtdMenorQNatural = 0;
    int qtdIgualQNatural = 0;

    for (int i = 0; i < lista.length; i++) {
      if (lista[i] > natural) {
        qtdMaiorQNatural++;
      } else if (lista[i] < natural) {
        qtdMenorQNatural++;
      } else {
        qtdIgualQNatural++;
      }
    }

    System.out.println("Maior que o natural: " + qtdMaiorQNatural);
    System.out.println("Menor que o natural: " + qtdMenorQNatural);
    System.out.println("Igual ao natural: " + qtdIgualQNatural);
  }
}
