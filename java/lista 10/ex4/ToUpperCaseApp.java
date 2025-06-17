public class ToUpperCaseApp {
  public static void main(String[] args) {
    String input = "Hello, World!";
    String emptyInput = "";
    String result = ToUpperCase.processar(input);
    String emptyResult = ToUpperCase.processar(emptyInput);
    System.out.println("Original: " + input);
    System.out.println("Uppercase: " + result);
    System.out.println("Original: " + emptyInput);
    System.out.println("Uppercase: " + emptyResult);
  }
}
