public class NewString {
  public static String generate(String str) {
    if (str.length() < 8) {
      System.out.println("String deve ter pelo menos 8 caracteres.");
      return str;
    } else {
      String firstTwo = str.substring(0, 2);
      String lastTwo = str.substring(str.length() - 2);

      return firstTwo + lastTwo;
    }
  }
}
