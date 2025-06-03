public class ListaApp {

  

  public static void main(String args[]) {
    int argumentos[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    Lista lista = new Lista(argumentos, 7);

    System.out.println("Maior diferença consecutiva: " + lista.getMaiorDiferencaConsecutiva());
    lista.tipoOrdenacao();
    lista.comparaNatural();
  }
}
