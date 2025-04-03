public class Fatura {
    private String numero, descricao;
    private int qtdItem;
    private double preco;

    public Fatura(String numero, String descricao, int qtdItem, double preco) {
        this.numero = numero;
        this.descricao = descricao;
        this.qtdItem = qtdItem;
        this.preco = preco;
    }

    public String getNumero() {
        return this.numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public String getDescricao() {
        return this.descricao;
    }

    public void setDescricao(String descricao) {
        this.descricao = descricao;
    }

    public int getQtdItem() {
        return this.qtdItem;
    }

    public void setQtdItem(int qtdItem) {
        this.qtdItem = qtdItem;
    }

    public double getPreco() {
        return this.preco;
    }

    public void setPreco(double preco) {
        this.preco = preco;
    }

    public double getQtdeFatura() {
        return qtdItem * preco;
    }
}