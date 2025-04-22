class Monitor {
  private boolean ligado;

  public Monitor() {
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
      System.out.println("A Monitor está ligado.");
    } else {
      System.out.println("A Monitor está desligado.");
    }
  }
}
