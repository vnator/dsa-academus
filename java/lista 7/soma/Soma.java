public class Soma {
  private int[] lista;

  public Soma(int[] lista) {
    this.lista = lista;
  }

  public int calc() {
    int soma = 0;

    for (int item: lista) { soma += item; }

    return soma;
  }
}
