public class CompareStrApp {
  public static void main(String[] args) {
    String str1 = "Hello World";
    String str2 = "hello world";
    String str3 = "Hello World";
    String str4 = "another";

    boolean strictComparison = CompareStr.strict(str1, str3);
    boolean ignoreCaseComparison = CompareStr.ignoreCase(str1, str2);

    System.out.println("Comparação estrita: " + (strictComparison ? "Verdadeiro" : "Falso"));
    System.out.println("Comparação ignorando maiúsculas/minúsculas: " + (ignoreCaseComparison ? "Verdadeiro" : "Falso"));

    System.out.println("Comparação estrita com strings diferentes: " + (CompareStr.strict(str1, str4) ? "Verdadeiro" : "Falso"));
    System.out.println("Comparação ignorando maiúsculas/minúsculas com strings diferentes: " + (CompareStr.ignoreCase(str1, str4) ? "Verdadeiro" : "Falso"));
  }
}
