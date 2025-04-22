class Cozinha {

  private Liquidificador liquidificador;
  private Microondas microondas;
  private Geladeira geladeira;

  public Cozinha (Liquidificador liquidificador, Microondas microondas, Geladeira geladeira) {
    this.liquidificador = liquidificador;
    this.microondas = microondas;
    this.geladeira = geladeira;
  }

  public void ligar() {
    liquidificador.ligar();
    microondas.ligar();
    geladeira.ligar();
  }

  public void desligar() {
    liquidificador.desligar();
    microondas.desligar();
    geladeira.desligar();
  }

  public void observar() {
    liquidificador.observar();
    microondas.observar();
    geladeira.observar();
  }

  public void isLigado() {
    if (liquidificador.isLigado() && microondas.isLigado() && geladeira.isLigado()) {
      System.out.println("A cozinha está ligada.");
    } else {
      System.out.println("A cozinha está desligada.");
    }
  }
}
