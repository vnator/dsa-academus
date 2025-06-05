public class ProtegidoApp {
  public static void main(String[] args) {
    Protegido exemplo = new Protegido(8);
    System.out.println("x: " + exemplo.getI());

    ProtegidoSub subExemplo = new ProtegidoSub(4);
    subExemplo.mudar(12);
    System.out.println("x: " + subExemplo.getI());
  }
}
