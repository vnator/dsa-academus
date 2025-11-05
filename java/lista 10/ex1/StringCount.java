public class StringCount {

  private static final String vogais = "aeiou";

  public static int qtdChars(String entrada) {
    return entrada.length();
  }

  public static int qtdVogais(String entrada) {
    if (entrada == null || entrada.isEmpty()) {
      return 0;
    }

    int count = 0;
    String minusculo = entrada.toLowerCase();

    for (int i = 0; i < minusculo.length(); i++) {
      char letra = minusculo.charAt(i);

      if (vogais.contains(String.valueOf(letra))) { count++; }
    }

    return count;
  }
}
