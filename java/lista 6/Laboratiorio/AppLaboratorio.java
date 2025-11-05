class AppLaboratorio {
  

  public static void main(String[] args) {
    Computador computador = new Computador();
    Monitor monitor = new Monitor();
    Nobreak nobreak = new Nobreak();

    Laboratorio laboratorio = new Laboratorio(computador, monitor, nobreak);

    
    laboratorio.isLigado();
    laboratorio.ligar();
    laboratorio.observar();
    laboratorio.isLigado();
    laboratorio.desligar();
    laboratorio.observar();
  }
}
