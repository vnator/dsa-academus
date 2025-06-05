public class ClienteEspecial extends ContaCorrente {
  public ClienteEspecial(double saldoInicial) {
    super(saldoInicial);
    setTaxa(0.01);
  }
}
