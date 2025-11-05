public class Pedido {
  private int numero;
  private Cliente cliente;
  private Veiculo veiculo;

  public Pedido(Cliente cliente, Veiculo veiculo) {
      this.cliente = cliente;
      this.veiculo = veiculo;
      this.numero = gerarNumeroPedido();
  }

  private int gerarNumeroPedido() {
      return (int) (Math.random() * 10000);
  }

  public void printDados() {
      System.out.println("Número do Pedido: " + numero);
      System.out.println("Dados do Cliente:");
      cliente.printDados();
      System.out.println("Dados do Veículo:");
      veiculo.printDados();
  }
}
