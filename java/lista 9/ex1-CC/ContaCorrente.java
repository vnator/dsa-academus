public class ContaCorrente {
  private double saldo;
  private double taxa = 0.05;

  public ContaCorrente(double saldoInicial) {
    this.saldo = saldoInicial;
  }

  public void depositar(double valor) {
    if (valor > 0) {
      saldo += valor;
    } else {
      System.out.println("Valor de depósito inválido.");
    }
  }

  public void saque(double valor) {
    double saquePossivel = valor + (valor * taxa);

    if (saquePossivel <= saldo) {
      saldo -= saquePossivel;
      System.out.println("Saque realizado com sucesso. Saldo atual: " + saldo);
      System.out.println("Saque: " + valor + ", Taxa: " + (valor * taxa));
    } else {
      System.out.println("Saldo Insuficiente");
    }
  }

  public double getSaldo() {
    return saldo;
  }

  public double getTaxa() {
    return taxa;
  }

  protected void setTaxa(double taxa) {
    this.taxa = taxa;
  }
}

