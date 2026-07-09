public class Money implements PaymentMethod {
  private double saldo;

  public Money(double saldoInicial) {
    this.saldo = saldoInicial;
  }

  @Override
  public boolean validar() {
    return this.saldo > 0;
  }

  @Override
  public boolean processarPagamento(double valor) {
    if (!validar()) {
      System.out.println("Sem dinheiro!");
      return false;
    }

    if (valor > this.saldo) {
      System.out.println("Saldo insuficiente!");
      return false;
    }

    this.saldo -= valor;
    return true;
  }

  @Override
  public String obterNomeMetodo() {
    return "Dinheiro em Espécie";
  }

  @Override
  public String obterDetalhes() {
    return "Saldo disponível: R$ " + String.format("%.2f", this.saldo);
  }

  public double getSaldo() {
    return this.saldo;
  }

  public void adicionarSaldo(double valor) {
    if (valor > 0) {
      this.saldo += valor;
    }
  }

  public void removerSaldo(double valor) {
    if (valor > 0 && valor <= this.saldo) {
      this.saldo -= valor;
    }
  }
}
