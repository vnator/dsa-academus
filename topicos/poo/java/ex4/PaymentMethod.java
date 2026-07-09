public interface PaymentMethod {
  boolean validar();

  boolean processarPagamento(double valor);

  String obterNomeMetodo();

  String obterDetalhes();
}
