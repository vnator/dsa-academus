public class Main {
    public static void main(String[] args) {
        System.out.println("=== SIMULAÇÃO DE BARALHO DE CARTAS ===\n");
        
        Baralho baralho = new Baralho();
        
        System.out.println("Baralho criado com " + baralho.cartasRestantes() + " cartas.\n");
        
        baralho.embaralhar();
        System.out.println("Baralho embaralhado!\n");
        
        System.out.println("Distribuindo 5 cartas:\n");
        for (int i = 0; i < 5; i++) {
            Carta carta = baralho.comprar();
            if (carta != null) {
                System.out.println(carta);
            }
        }
        
        System.out.println("\nCartas restantes no baralho: " + baralho.cartasRestantes());
    }
}
