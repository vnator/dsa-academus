class Liquidificador {
  private boolean ligado;

  public Liquidificador() {
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
      System.out.println("O liquidificador está ligado.");
    } else {
      System.out.println("O liquidificador está desligado.");
    }
  }
}
