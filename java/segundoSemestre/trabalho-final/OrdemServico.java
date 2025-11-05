enum OrdemStatusServer {
    AGUARDANDO,
    EM_ANDAMENTO,
    CONCLUIDO,
    CANCELADO
}


class OrdemServico implements Reparavel {
    private Cliente cliente;
    private Veiculo veiculo;
    private Mecanico mecanico;
    private Servico servico;
    private String data;
    private OrdemStatusServer status;

    OrdemServico(Cliente cliente, Veiculo veiculo, Mecanico mecanico, Servico servico, String data, OrdemStatusServer status) {
        this.cliente = cliente;
        this.veiculo = veiculo;
        this.mecanico = mecanico;
        this.servico = servico;
        this.data = data;
        this.status = status;
    }

    
    @Override
    public void reparar() {
        if (status == OrdemStatusServer.AGUARDANDO) {
            status = OrdemStatusServer.EM_ANDAMENTO;
        }
        
        status = OrdemStatusServer.CONCLUIDO;
    }

    public Veiculo getVeiculo() {
        return veiculo;
    }

    public Mecanico getMecanico() {
        return mecanico;
    }

    public Servico getServico() {
        return servico;
    }

    public String getData() {
        return data;
    }

    public OrdemStatusServer getStatus() {
        return status;
    }

    public Cliente getCliente() {
        return cliente;
    }

    public void setStatus(OrdemStatusServer status) {
        this.status = status;
    }
}