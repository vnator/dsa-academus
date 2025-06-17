public class NewStringApp {
  public static void main(String[] args) {
    String str = "Hello World";
    String strError = "Hello";

    String result = NewString.generate(str);
    String resultError = NewString.generate(strError);

    System.out.println("Resultado: " + result);
    System.out.println("Resultado com erro: " + resultError);
  }
}


