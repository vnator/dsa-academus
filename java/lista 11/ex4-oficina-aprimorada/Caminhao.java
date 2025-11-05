public class Caminhao extends Veiculo {
  public Caminhao() {
    System.out.println("É um caminhão");
  }

  @Override
  public void verificar() {
    System.out.println("Verificar caminhão");
  }

  @Override
  public void ajustar() {
    System.out.println("Ajustar caminhão");
  }

  @Override
  public void limpar() {
    System.out.println("Limpar caminhão");
  }
}
