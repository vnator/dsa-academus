class Laboratorio {

  private Computador computador;
  private Monitor monitor;
  private Nobreak nobreak;

  public Laboratorio (Computador computador, Monitor monitor, Nobreak nobreak) {
    this.computador = computador;
    this.monitor = monitor;
    this.nobreak = nobreak;
  }

  public void ligar() {
    computador.ligar();
    monitor.ligar();
    nobreak.ligar();
  }

  public void desligar() {
    computador.desligar();
    monitor.desligar();
    nobreak.desligar();
  }

  public void observar() {
    computador.observar();
    monitor.observar();
    nobreak.observar();
  }

  public void isLigado() {
    if (computador.isLigado() && monitor.isLigado() && nobreak.isLigado()) {
      System.out.println("O Laboratorio está ligado.");
    } else {
      System.out.println("O Laboratorio está desligado.");
    }
  }
}
