public class Oficina {
  public void concertar(Veiculo v) {
    this.verificar(v);
    this.ajustar(v);
    this.limpar(v);
  }

  private void verificar(Veiculo v) {}
  private void ajustar(Veiculo v) {}
  private void limpar(Veiculo v) {}
}
