public class CreditCard implements PaymentMethod {
  private String numero;
  private String titular;
  private String dataValidade;
  private String cvv;
  private double limite;
  private double saldoUtilizado;

  public CreditCard(String numero, String titular, String dataValidade, String cvv, double limite) {
    this.numero = numero;
    this.titular = titular;
    this.dataValidade = dataValidade;
    this.cvv = cvv;
    this.limite = limite;
    this.saldoUtilizado = 0;
  }

  @Override
  public boolean validar() {
    if (this.numero == null || this.numero.length() != 16) {
      return false;
    }
    if (this.cvv == null || this.cvv.length() != 3) {
      return false;
    }
    return !this.dataValidade.isEmpty();
  }

  @Override
  public boolean processarPagamento(double valor) {
    if (!validar()) {
      System.out.println("Cartão inválido!");
      return false;
    }

    if (this.saldoUtilizado + valor > this.limite) {
      System.out.println("Limite insuficiente!");
      return false;
    }

    this.saldoUtilizado += valor;
    return true;
  }

  @Override
  public String obterNomeMetodo() {
    return "Cartão de Crédito";
  }

  @Override
  public String obterDetalhes() {
    return "Cartão terminado em " + this.numero.substring(12) + 
           " | Titular: " + this.titular + 
           " | Saldo disponível: " + String.format("%.2f", (this.limite - this.saldoUtilizado));
  }

  public double getLimite() {
    return this.limite;
  }

  public double getSaldoUtilizado() {
    return this.saldoUtilizado;
  }

  public String getNumero() {
    return this.numero;
  }

  public String getTitular() {
    return this.titular;
  }
}
