class Geladeira {
  private boolean ligado;

  public Geladeira() {
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
      System.out.println("A Geladeira está ligado.");
    } else {
      System.out.println("A Geladeira está desligado.");
    }
  }
}
