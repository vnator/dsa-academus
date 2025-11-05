public class TesteUsuarioDispositivo {
  public static void main(String[] args) {
    Usuario usuario1 = new Usuario("Theodoro", 123456);
    Dispositivo dispositivo1 = new Dispositivo("Notebook", 123);

    Usuario usuario2 = new Usuario("Ana", 654321);
    Dispositivo dispositivo2 = new Dispositivo("Desktop", 456);

    usuario1.setDispositivo(dispositivo1);
    usuario2.setDispositivo(dispositivo2);

    usuario1.trabalhar();
    usuario2.trabalhar();
  }
}
