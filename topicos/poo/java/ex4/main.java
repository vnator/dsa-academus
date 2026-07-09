import java.util.ArrayList;
import java.util.List;

public class main {
  public static void main(String[] args) {
    List<PaymentMethod> metodosPagamento = new ArrayList<>();

    // Criando diferentes métodos de pagamento
    CreditCard cartao = new CreditCard("1234567890123456", "Joao Silva", "12/26", "123", 5000);
    Money dinheiro = new Money(2000);
    Pix pix = new Pix("joao@email.com", "Joao Silva", "Banco do Brasil", 3500);

    // Adicionando à lista
    metodosPagamento.add(cartao);
    metodosPagamento.add(dinheiro);
    metodosPagamento.add(pix);

    // Exibindo informações de cada método
    System.out.println("=== Métodos de Pagamento Disponíveis ===\n");
    for (PaymentMethod metodo : metodosPagamento) {
      System.out.println(metodo.obterNomeMetodo());
      System.out.println(metodo.obterDetalhes());
      System.out.println();
    }

    // Testando pagamentos
    System.out.println("=== Processando Pagamentos ===\n");

    double valor1 = 150.50;
    System.out.println("Pagamento de R$ " + String.format("%.2f", valor1) + " com " + cartao.obterNomeMetodo());
    if (cartao.processarPagamento(valor1)) {
      System.out.println("✓ Pagamento realizado com sucesso!");
    } else {
      System.out.println("✗ Pagamento falhou!");
    }
    System.out.println();

    double valor2 = 500;
    System.out.println("Pagamento de R$ " + String.format("%.2f", valor2) + " com " + dinheiro.obterNomeMetodo());
    if (dinheiro.processarPagamento(valor2)) {
      System.out.println("✓ Pagamento realizado com sucesso!");
    } else {
      System.out.println("✗ Pagamento falhou!");
    }
    System.out.println();

    double valor3 = 1200;
    System.out.println("Pagamento de R$ " + String.format("%.2f", valor3) + " com " + pix.obterNomeMetodo());
    if (pix.processarPagamento(valor3)) {
      System.out.println("✓ Pagamento realizado com sucesso!");
    } else {
      System.out.println("✗ Pagamento falhou!");
    }
    System.out.println();

    // Testando pagamento com valor insuficiente
    double valor4 = 3000;
    System.out.println("Pagamento de R$ " + String.format("%.2f", valor4) + " com " + dinheiro.obterNomeMetodo());
    if (dinheiro.processarPagamento(valor4)) {
      System.out.println("✓ Pagamento realizado com sucesso!");
    } else {
      System.out.println("✗ Pagamento falhou!");
    }
    System.out.println();

    // Exibindo saldos atualizados
    System.out.println("=== Saldos Após os Pagamentos ===\n");
    for (PaymentMethod metodo : metodosPagamento) {
      System.out.println(metodo.obterNomeMetodo());
      System.out.println(metodo.obterDetalhes());
      System.out.println();
    }
  }
}
