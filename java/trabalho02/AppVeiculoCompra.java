public class AppVeiculoCompra {
  private static Veiculo[] veiculos = new Veiculo[10];
  private static Cliente[] clientes = new Cliente[10];
  private static Pedido[] pedidos = new Pedido[10];
  private static int contadorClientes = 0;
  private static int contadorVeiculos = 0;
  private static int contadorPedidos = 0;

  public static void main(String[] args) {
    int opcao = 0;

    while (opcao != 6) {
      System.out.println("Menu:");
      System.out.println("1 - Listar Clientes");
      System.out.println("2 - Listar Veículos");
      System.out.println("3 - Cadastrar Cliente");
      System.out.println("4 - Cadastrar Veículo");
      System.out.println("5 - Cadastrar Pedido");
      System.out.println("6 - Sair");

      opcao = Integer.parseInt(System.console().readLine("Escolha uma opção: "));

      switch (opcao) {
        case 1:
          listarClientes();
          break;
        case 2:
          listarVeiculos();
          break;
        case 3:
          cadastrarCliente();
          break;
        case 4:
          cadastrarVeiculo();
          break;
        case 5:
          cadastrarPedido();
          break;
        case 6:
          System.out.println("Saindo...");
          break;
        default:
          System.out.println("Opção inválida. Tente novamente.");
      }
    }
  }

  public static void listarClientes() {
    for (int i = 0; i < contadorClientes; i++) {
      if (clientes[i] != null) {
        System.out.println((i + 1) + " - " + clientes[i].toString());
      }
    }
    
    if (contadorClientes == 0) {
      System.out.println("Nenhum cliente cadastrado.");
    }
  }

  public static void listarVeiculos() {
    for (int i = 0; i < contadorVeiculos; i++) {
      if (veiculos[i] != null) {
        System.out.println((i + 1) + " - " + veiculos[i].toString());
      }
    }
    
    if (contadorVeiculos == 0) {
      System.out.println("Nenhum veículo cadastrado.");
    }
  }

  public static void cadastrarCliente() {
    if (contadorClientes >= 10) {
      System.out.println("Limite de clientes atingido.");
      return;
    }

    String nome = System.console().readLine("Digite o nome do cliente: ");
    String cpf = System.console().readLine("Digite o CPF do cliente: ");

    clientes[contadorClientes] = new Cliente(nome, cpf);
    System.out.println("Cliente cadastrado com sucesso!");
    clientes[contadorClientes].printDados();
    contadorClientes++;
  }

  public static void cadastrarVeiculo() {
    if (contadorVeiculos >= 10) {
      System.out.println("Limite de veículos atingido.");
      return;
    }

    int tipoVeiculo = Integer.parseInt(System.console().readLine("Digite o tipo do veículo, 1 para Carro, 2 para Moto: "));

    String modelo = System.console().readLine("Digite o modelo do veículo: ");
    double preco = Double.parseDouble(System.console().readLine("Digite o preço do veículo: "));

    if (tipoVeiculo == 1) {
      int ano = Integer.parseInt(System.console().readLine("Digite o ano do veículo: "));
      veiculos[contadorVeiculos] = new Carro(modelo, preco, ano);
    } else if (tipoVeiculo == 2) {
      double km = Double.parseDouble(System.console().readLine("Digite a quilometragem do veículo: "));
      veiculos[contadorVeiculos] = new Moto(modelo, preco, km);
    } else {
      System.out.println("Tipo de veículo inválido.");
      return;
    }

    System.out.println("Veículo cadastrado com sucesso!");
    veiculos[contadorVeiculos].printDados();
    contadorVeiculos++;
  }

  public static void cadastrarPedido() {
    if (contadorPedidos >= 10) {
      System.out.println("Limite de pedidos atingido.");
      return;
    }
    
    if (contadorClientes == 0) {
      System.out.println("Nenhum cliente cadastrado. Cadastre um cliente primeiro.");
      return;
    }
    
    if (contadorVeiculos == 0) {
      System.out.println("Nenhum veículo cadastrado. Cadastre um veículo primeiro.");
      return;
    }
    
    listarClientes();
    int clienteIndex = Integer.parseInt(System.console().readLine("Selecione o cliente pelo número: ")) - 1;

    if (clienteIndex < 0 || clienteIndex >= contadorClientes || clientes[clienteIndex] == null) {
      System.out.println("Cliente inválido.");
      return;
    }

    listarVeiculos();
    int veiculoIndex = Integer.parseInt(System.console().readLine("Selecione o veículo pelo número: ")) - 1;
    if (veiculoIndex < 0 || veiculoIndex >= contadorVeiculos || veiculos[veiculoIndex] == null) {
      System.out.println("Veículo inválido.");
      return;
    }

    pedidos[contadorPedidos] = new Pedido(clientes[clienteIndex], veiculos[veiculoIndex]);
    System.out.println("Pedido cadastrado com sucesso!");
    pedidos[contadorPedidos].printDados();
    contadorPedidos++;
  }
}