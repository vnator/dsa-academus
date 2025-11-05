import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Baralho {
    private List<Carta> cartas;
    
    public Baralho() {
        cartas = new ArrayList<>();
        
        for (Naipe naipe : Naipe.values()) {
            for (Valor valor : Valor.values()) {
                cartas.add(new Carta(valor, naipe));
            }
        }
    }
    
    public void embaralhar() {
        Collections.shuffle(cartas);
    }
    
    public Carta comprar() {
        if (cartas.isEmpty()) {
            return null;
        }
        return cartas.remove(0);
    }
    
    public int cartasRestantes() {
        return cartas.size();
    }
}
