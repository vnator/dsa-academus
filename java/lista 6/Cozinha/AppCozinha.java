class AppCozinha {
  

  public static void main(String[] args) {
    Microondas microondas = new Microondas();
    Liquidificador liquidificador = new Liquidificador();
    Geladeira geladeira = new Geladeira();

    Cozinha cozinha = new Cozinha(liquidificador, microondas, geladeira);

    
    cozinha.isLigado();
    cozinha.ligar();
    cozinha.observar();
    cozinha.isLigado();
    cozinha.desligar();
    cozinha.observar();
  }
}
