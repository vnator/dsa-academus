public class OficinaApp {
  public static void main(String[] args) {
    Veiculo automovel = new Automovel();
    Veiculo bicicleta = new Bicicleta();
    
    Oficina oficina = new Oficina();
    
    oficina.concertar(automovel);
    oficina.concertar(bicicleta);
  }
}
