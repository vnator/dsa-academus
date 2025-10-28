class Oficina {
    private String nome;
    private List<Cliente> clientes;
    private List<Mecanico> mecanicos;
    private List<Servico> servicos;
    private List<OrdemServico> ordensServico;


    Oficina(String nome) {
        this.nome = nome;
        clientes = new ArrayList<>();
        mecanicos = new ArrayList<>();
        servicos = new ArrayList<>();
        ordensServico = new ArrayList<>();
    }

    public void adicionarCliente(Cliente cliente) {
        clientes.add(cliente);
    }

    public void adicionarMecanico(Mecanico mecanico) {
        mecanicos.add(mecanico);
    }

    public void adicionarServico(Servico servico) {
        servicos.add(servico);
    }

    public void criarOrdemServico(Cliente cliente, Veiculo veiculo, Mecanico mecanico, Servico servico, String data) {
        try {
            if (!servico.isDisponivel()) {
                throw new ServicoIndisponivelException("Serviço não disponível");
            }
            
            if (!veiculo.getCliente().equals(cliente)) {
                throw new VeiculoNaoEncontradoException("Veículo não encontrado para o Cliente");
            }

            if (!veiculo.getTipo().equals(mecanico.getEspecialidade())) {
                throw new MecanicoNaoEspecializadoException("Mecânico não especializado para este tipo de veículo");
            }

            OrdemServico ordemServico = new OrdemServico(cliente, veiculo, mecanico, servico, data, OrdemStatusServer.AGUARDANDO);
            ordensServico.add(ordemServico);
        } catch (Exception e) {
            System.out.println("Erro ao criar ordem de serviço: " + e.getMessage());
        }
    }

    public List<OrdemServico> getOrdensServico() {
        return ordensServico;
    }

    public List<OrdemServico> getOrdemServico(Veiculo veiculo) {
        List<OrdemServico> ordensEncontradas = new ArrayList<>();
        for (OrdemServico ordem : ordensServico) {
            if (ordem.getVeiculo().equals(veiculo)) {
                ordensEncontradas.add(ordem);
            }
        }
        return ordensEncontradas;
    }

    public List<OrdemServico> getOrdemServico(Mecanico mecanico) {
        List<OrdemServico> ordensEncontradas = new ArrayList<>();
        for (OrdemServico ordem : ordensServico) {
            if (ordem.getMecanico().equals(mecanico)) {
                ordensEncontradas.add(ordem);
            }
        }
        return ordensEncontradas;
    }

    public List<OrdemServico> getOrdemServico(Servico servico) {
        List<OrdemServico> ordensEncontradas = new ArrayList<>();
        for (OrdemServico ordem : ordensServico) {
            if (ordem.getServico().equals(servico)) {
                ordensEncontradas.add(ordem);
            }
        }
        return ordensEncontradas;
    }

    public List<OrdemServico> getOrdemServico(Cliente cliente) {
        List<OrdemServico> ordensEncontradas = new ArrayList<>();
        for (OrdemServico ordem : ordensServico) {
            if (ordem.getCliente().equals(cliente)) {
                ordensEncontradas.add(ordem);
            }
        }
        return ordensEncontradas;
    }
}