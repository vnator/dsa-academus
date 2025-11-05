public class ContaApp {
  public static void main(String[] args) {
    ContaCorrente conta = new ContaCorrente(1000.0);
    System.out.println("Saldo inicial: " + conta.getSaldo());

    conta.depositar(500.0);
    System.out.println("Saldo após depósito: " + conta.getSaldo());

    conta.saque(200.0);
    System.out.println("Saldo após saque: " + conta.getSaldo());
    System.out.println("Taxa de saque: " + conta.getTaxa());

    ClienteEspecial clienteEspecial = new ClienteEspecial(1000.0);
    System.out.println("Saldo inicial Cliente Especial: " + clienteEspecial.getSaldo());

    clienteEspecial.depositar(500.0);
    System.out.println("Saldo após depósito Cliente Especial: " + clienteEspecial.getSaldo());

    clienteEspecial.saque(200.0);
    System.out.println("Saldo após saque Cliente Especial: " + clienteEspecial.getSaldo());
    System.out.println("Taxa de saque Cliente Especial: " + clienteEspecial.getTaxa());
  }
}
