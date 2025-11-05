class Servico {
    private String descricao;
    private double preco;
    private boolean disponivel;

    Servico(String descricao, double preco) {
        this.descricao = descricao;
        this.preco = preco;
        this.disponivel = true;
    }

    public String getDescricao() {
        return descricao;
    }

    public double getPreco() {
        return preco;
    }

    public boolean isDisponivel() {
        return disponivel;
    }

    public void setDisponivel(boolean disponivel) {
        this.disponivel = disponivel;
    }
}