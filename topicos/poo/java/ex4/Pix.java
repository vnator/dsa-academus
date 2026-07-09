public class Pix implements PaymentMethod {
  private String chave;
  private String titularConta;
  private String banco;
  private double saldo;

  public Pix(String chave, String titularConta, String banco, double saldoInicial) {
    this.chave = chave;
    this.titularConta = titularConta;
    this.banco = banco;
    this.saldo = saldoInicial;
  }

  @Override
  public boolean validar() {
    return this.chave != null && !this.chave.isEmpty() && 
           this.titularConta != null && !this.titularConta.isEmpty() &&
           this.saldo > 0;
  }

  @Override
  public boolean processarPagamento(double valor) {
    if (!validar()) {
      System.out.println("Chave PIX inválida ou conta sem saldo!");
      return false;
    }

    if (valor > this.saldo) {
      System.out.println("Saldo insuficiente na conta!");
      return false;
    }

    this.saldo -= valor;
    return true;
  }

  @Override
  public String obterNomeMetodo() {
    return "PIX";
  }

  @Override
  public String obterDetalhes() {
    return "PIX - " + this.banco + 
           " | Titular: " + this.titularConta + 
           " | Saldo: R$ " + String.format("%.2f", this.saldo);
  }

  public String getChave() {
    return this.chave;
  }

  public String getTitularConta() {
    return this.titularConta;
  }

  public String getBanco() {
    return this.banco;
  }

  public double getSaldo() {
    return this.saldo;
  }

  public void setSaldo(double saldo) {
    if (saldo >= 0) {
      this.saldo = saldo;
    }
  }
}
