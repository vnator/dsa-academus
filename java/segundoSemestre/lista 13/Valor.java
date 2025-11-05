public enum Valor {
    AS("Ás"),
    DOIS("2"),
    TRES("3"),
    QUATRO("4"),
    CINCO("5"),
    SEIS("6"),
    SETE("7"),
    OITO("8"),
    NOVE("9"),
    DEZ("10"),
    VALETE("Valete"),
    DAMA("Dama"),
    REI("Rei");
    
    private final String nome;
    
    Valor(String nome) {
        this.nome = nome;
    }
    
    public String getNome() {
        return nome;
    }
}
