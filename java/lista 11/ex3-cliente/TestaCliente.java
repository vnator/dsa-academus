public class TestaCliente {
  Cliente c1 = new Cliente();
  ClienteEspecial c2 = new ClienteEspecial();

  public void testaDesconto() {
    double valor = 1200.0;
    double descontoC1 = c1.calcularDesconto(valor);
    double descontoC2 = c2.calcularDesconto(valor);

    System.out.println("Desconto Cliente Comum: " + descontoC1);
    System.out.println("Desconto Cliente Especial: " + descontoC2);
  }

  public static void main(String[] args) {
    TestaCliente teste = new TestaCliente();
    teste.testaDesconto();
  }
}
