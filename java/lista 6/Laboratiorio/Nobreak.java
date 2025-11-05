class Nobreak {
  private boolean ligado;

  public Nobreak() {
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
      System.out.println("A Nobreak está ligado.");
    } else {
      System.out.println("A Nobreak está desligado.");
    }
  }
}
