class Microondas {
  private boolean ligado;

  public Microondas() {
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
    if (ligado)
      System.out.println("O microondas está ligado.");
    else
      System.out.println("O microondas está desligado.");
  }
}

