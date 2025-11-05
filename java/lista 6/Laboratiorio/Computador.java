class Computador {
  private boolean ligado;

  public Computador() {
    this.ligado = false;
  }

  public void ligar() {
    ligado = true;
  }

  public void desligar() {
    ligado = false; 
  }

  public boolean isLigado() {
    return ligado;
  }

  public void observar() {
    if (ligado) {
      System.out.println("A Coputador está ligado.");
    } else {
      System.out.println("A Coputador está desligado.");
    }
  }
}
