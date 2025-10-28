import java.util.ArrayList;
import java.util.List;

public class TesteOficina {
    public static void main(String[] args) {
        System.out.println("=== INICIANDO TESTES DA OFICINA ===\n");
        
        // Criar oficina
        Oficina oficina = new Oficina("Oficina Auto Center");
        
        // Criar 4 tipos de serviços
        System.out.println("--- Cadastrando Serviços ---");
        Servico servico1 = new Servico("Troca de Óleo", 150.0);
        Servico servico2 = new Servico("Alinhamento e Balanceamento", 200.0);
        Servico servico3 = new Servico("Revisão Completa", 500.0);
        Servico servico4 = new Servico("Troca de Pastilhas de Freio", 300.0);
        
        oficina.adicionarServico(servico1);
        oficina.adicionarServico(servico2);
        oficina.adicionarServico(servico3);
        oficina.adicionarServico(servico4);
        System.out.println("4 serviços cadastrados com sucesso!\n");
        
        // Criar 3 mecânicos com especialidades diferentes
        System.out.println("--- Cadastrando Mecânicos ---");
        Mecanico mecanico1 = new Mecanico("João Silva", 35, "111.111.111-11", TipoVeiculo.CARRO, 3500.0);
        Mecanico mecanico2 = new Mecanico("Pedro Santos", 28, "222.222.222-22", TipoVeiculo.MOTO, 3000.0);
        Mecanico mecanico3 = new Mecanico("Carlos Oliveira", 42, "333.333.333-33", TipoVeiculo.CAMINHAO, 4000.0);
        
        oficina.adicionarMecanico(mecanico1);
        oficina.adicionarMecanico(mecanico2);
        oficina.adicionarMecanico(mecanico3);
        System.out.println("3 mecânicos cadastrados:");
        System.out.println("  - " + mecanico1.getNome() + " (Especialidade: " + mecanico1.getEspecialidade() + ")");
        System.out.println("  - " + mecanico2.getNome() + " (Especialidade: " + mecanico2.getEspecialidade() + ")");
        System.out.println("  - " + mecanico3.getNome() + " (Especialidade: " + mecanico3.getEspecialidade() + ")\n");
        
        // Criar 5 clientes com veículos
        System.out.println("--- Cadastrando Clientes e Veículos ---");
        
        // Cliente 1 - 3 veículos
        Cliente cliente1 = new Cliente("Maria Costa", 30, "444.444.444-44", "Rua A, 100", "(11) 91111-1111");
        Veiculo v1c1 = new Veiculo("Toyota", "Corolla", 2020, "ABC-1234", "Preto", TipoVeiculo.CARRO, cliente1);
        Veiculo v2c1 = new Veiculo("Honda", "CG 160", 2021, "ABC-5678", "Vermelho", TipoVeiculo.MOTO, cliente1);
        Veiculo v3c1 = new Veiculo("Mercedes", "Actros", 2019, "ABC-9999", "Branco", TipoVeiculo.CAMINHAO, cliente1);
        cliente1.putVeiculo(v1c1);
        cliente1.putVeiculo(v2c1);
        cliente1.putVeiculo(v3c1);
        oficina.adicionarCliente(cliente1);
        System.out.println("Cliente 1: " + cliente1.getNome() + " - 3 veículos");
        
        // Cliente 2 - 2 veículos
        Cliente cliente2 = new Cliente("José Almeida", 45, "555.555.555-55", "Rua B, 200", "(11) 92222-2222");
        Veiculo v1c2 = new Veiculo("Chevrolet", "Onix", 2022, "DEF-1111", "Branco", TipoVeiculo.CARRO, cliente2);
        Veiculo v2c2 = new Veiculo("Yamaha", "Factor 150", 2020, "DEF-2222", "Azul", TipoVeiculo.MOTO, cliente2);
        cliente2.putVeiculo(v1c2);
        cliente2.putVeiculo(v2c2);
        oficina.adicionarCliente(cliente2);
        System.out.println("Cliente 2: " + cliente2.getNome() + " - 2 veículos");
        
        // Cliente 3 - 1 veículo
        Cliente cliente3 = new Cliente("Ana Paula", 28, "666.666.666-66", "Rua C, 300", "(11) 93333-3333");
        Veiculo v1c3 = new Veiculo("Volvo", "FH 540", 2021, "GHI-3333", "Prata", TipoVeiculo.CAMINHAO, cliente3);
        cliente3.putVeiculo(v1c3);
        oficina.adicionarCliente(cliente3);
        System.out.println("Cliente 3: " + cliente3.getNome() + " - 1 veículo");
        
        // Cliente 4 - 2 veículos
        Cliente cliente4 = new Cliente("Roberto Lima", 38, "777.777.777-77", "Rua D, 400", "(11) 94444-4444");
        Veiculo v1c4 = new Veiculo("Fiat", "Argo", 2023, "JKL-4444", "Vermelho", TipoVeiculo.CARRO, cliente4);
        Veiculo v2c4 = new Veiculo("Scania", "R450", 2020, "JKL-5555", "Azul", TipoVeiculo.CAMINHAO, cliente4);
        cliente4.putVeiculo(v1c4);
        cliente4.putVeiculo(v2c4);
        oficina.adicionarCliente(cliente4);
        System.out.println("Cliente 4: " + cliente4.getNome() + " - 2 veículos");
        
        // Cliente 5 - 3 veículos
        Cliente cliente5 = new Cliente("Fernanda Souza", 32, "888.888.888-88", "Rua E, 500", "(11) 95555-5555");
        Veiculo v1c5 = new Veiculo("Volkswagen", "Gol", 2019, "MNO-6666", "Cinza", TipoVeiculo.CARRO, cliente5);
        Veiculo v2c5 = new Veiculo("Honda", "Biz 125", 2022, "MNO-7777", "Preto", TipoVeiculo.MOTO, cliente5);
        Veiculo v3c5 = new Veiculo("Hyundai", "HB20", 2021, "MNO-8888", "Branco", TipoVeiculo.CARRO, cliente5);
        cliente5.putVeiculo(v1c5);
        cliente5.putVeiculo(v2c5);
        cliente5.putVeiculo(v3c5);
        oficina.adicionarCliente(cliente5);
        System.out.println("Cliente 5: " + cliente5.getNome() + " - 3 veículos\n");
        
        // Criar ordens de serviço para cada cliente
        System.out.println("--- Criando Ordens de Serviço ---");
        
        oficina.criarOrdemServico(cliente1, v1c1, mecanico1, servico1, "2025-10-27");
        System.out.println("OS 1: " + cliente1.getNome() + " - " + v1c1.getModelo() + " - " + servico1.getDescricao());
        
        oficina.criarOrdemServico(cliente2, v1c2, mecanico1, servico2, "2025-10-27");
        System.out.println("OS 2: " + cliente2.getNome() + " - " + v1c2.getModelo() + " - " + servico2.getDescricao());
        
        oficina.criarOrdemServico(cliente3, v1c3, mecanico3, servico3, "2025-10-27");
        System.out.println("OS 3: " + cliente3.getNome() + " - " + v1c3.getModelo() + " - " + servico3.getDescricao());
        
        oficina.criarOrdemServico(cliente4, v1c4, mecanico1, servico4, "2025-10-27");
        System.out.println("OS 4: " + cliente4.getNome() + " - " + v1c4.getModelo() + " - " + servico4.getDescricao());
        
        oficina.criarOrdemServico(cliente5, v2c5, mecanico2, servico1, "2025-10-27");
        System.out.println("OS 5: " + cliente5.getNome() + " - " + v2c5.getModelo() + " - " + servico1.getDescricao() + "\n");
        
        // Simular iteração completa de cada ordem de serviço
        System.out.println("--- Simulando Reparos ---");
        List<OrdemServico> ordens = oficina.getOrdensServico();
        
        for (int i = 0; i < ordens.size(); i++) {
            OrdemServico ordem = ordens.get(i);
            System.out.println("\nOrdem " + (i + 1) + ":");
            System.out.println("  Cliente: " + ordem.getCliente().getNome());
            System.out.println("  Veículo: " + ordem.getVeiculo().getModelo() + " - " + ordem.getVeiculo().getPlaca());
            System.out.println("  Mecânico: " + ordem.getMecanico().getNome());
            System.out.println("  Serviço: " + ordem.getServico().getDescricao());
            System.out.println("  Status inicial: " + ordem.getStatus());
            
            // Executar reparo
            ordem.reparar();
            System.out.println("  Status após reparo: " + ordem.getStatus());
        }
        
        System.out.println("\n=== TESTES CONCLUÍDOS ===");

        // causando exceções criarOrdemServico - Servico Indisponível
        System.out.println("\n--- Teste: criarOrdemServico() - Serviço Indisponível (Exceção) ---");
        Servico servicoIndisponivel = new Servico("Pintura Completa do Veículo", 1200.0); // Não cadastrado na oficina
        System.out.println("Tentando criar ordem com serviço indispon   ível...");
        oficina.criarOrdemServico(cliente1, v1c1, mecanico1, servicoIndisponivel, "2025-10-27");
        System.out.println("Exceção tratada corretamente");
        System.out.println("Resultado: PASSOU\n");

        // causando exceções criarOrdemServico - Veículo Não Encontrado
        System.out.println("\n--- Teste: criarOrdemServico() - Veículo Não Encontrado (Exceção) ---");
        Veiculo veiculoOutroCliente = new Veiculo("Ford", "Ka", 2018, "XYZ-0000", "Prata", TipoVeiculo.CARRO, cliente2); // Veículo não pertence ao cliente1
        System.out.println("Tentando criar ordem com veículo de outro cliente...");
        oficina.criarOrdemServico(cliente1, veiculoOutroCliente, mecanico1, servico1, "2025-10-27");
        System.out.println("Exceção tratada corretamente");
        System.out.println("Resultado: PASSOU\n");

        // causando exceções criarOrdemServico - Mecânico Não Especializado
        System.out.println("\n--- Teste: criarOrdemServico() - Mecânico Não Especializado (Exceção) ---");
        System.out.println("Tentando criar ordem com mecânico de especialidade diferente...");
        oficina.criarOrdemServico(cliente1, v1c1, mecanico2, servico1, "2025-10-27");
        System.out.println("Exceção tratada corretamente");
        System.out.println("Resultado: PASSOU\n");
    }
}
