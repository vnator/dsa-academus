import java.util.List;
import java.util.ArrayList;

public class OficinaApp {
  public static void main(String[] args) {
    Automovel automovel1 = new Automovel();
    Bicicleta bicicleta1 = new Bicicleta();
    Caminhao caminhao1 = new Caminhao();

    List<Veiculo> veiculos = new ArrayList<>();
    veiculos.add(automovel1);
    veiculos.add(bicicleta1);
    veiculos.add(caminhao1);

    Oficina oficina = new Oficina(veiculos);

    oficina.setVeiculos(new Automovel());
    oficina.setVeiculos(new Bicicleta());

    oficina.concertar(caminhao1);

    oficina.concertarTodos();
  }
}