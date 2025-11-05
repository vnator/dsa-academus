public class Carta {
    private Naipe naipe;
    private Valor valor;
    
    public Carta(Valor valor, Naipe naipe) {
        this.valor = valor;
        this.naipe = naipe;
    }
    
    public Naipe getNaipe() {
        return naipe;
    }
    
    public Valor getValor() {
        return valor;
    }
    
    @Override
    public String toString() {
        return valor.getNome().toUpperCase() + " DE " + naipe.toString();
    }
}
