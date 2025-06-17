public class CompareStr {
  public static boolean strict(String st1, String st2) {
    return st1.equals(st2);
  }

  public static boolean ignoreCase(String st1, String st2) {
    return st1.equalsIgnoreCase(st2);
  }
}
